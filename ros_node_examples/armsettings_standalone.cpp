// Standalone test program for opening a Dynamixel serial port
// - Removes ROS dependencies from the original file
// - Uses std::cout / std::cerr for logging

#include "dynamixel_sdk/dynamixel_sdk.h"
#include <iostream>
#include <thread>
#include <chrono>

#define BAUDRATE 1000000
#define DEVICE_NAME "/dev/ttyUSB0"
#define PROTOCOL_VERSION 2.0



// forward declaration
static void readRegisterMap(dynamixel::PortHandler *portHandler, dynamixel::PacketHandler *packetHandler, uint8_t dxl_id);

int main (int argc, char * argv[])
{
    dynamixel::PortHandler * portHandler = dynamixel::PortHandler::getPortHandler(DEVICE_NAME);
    dynamixel::PacketHandler * packetHandler = dynamixel::PacketHandler::getPacketHandler(PROTOCOL_VERSION);

    bool opened = portHandler->openPort();
    if (!opened) {
      std::cerr << "Failed to open the port!" << std::endl;
      return -1;
    } else {
      std::cout << "Succeeded to open the port." << std::endl;
    }

    bool baud_ok = portHandler->setBaudRate(BAUDRATE);
    if (!baud_ok) {
      std::cerr << "Failed to set the baudrate!" << std::endl;
      portHandler->closePort();
      return -1;
    } else {
      std::cout << "Succeeded to set the baudrate." << std::endl;
    }

    int dxl_comm_result = COMM_TX_FAIL;
    uint32_t results32 = 0;
    uint16_t result16 = 0;
    uint8_t result8 = 0;
    dxl_comm_result = packetHandler->read2ByteTxRx(
      portHandler,
      1,
      0,     // ADDR_DRIVE_MODE
      &result16
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Model Number." << std::endl;
    } else {
      std::cout << "Succeeded to read Model Number." << std::endl;
      //print model number
      std::cout << "Model Number: " << result16 << std::endl;
    }

    dxl_comm_result = packetHandler->read4ByteTxRx(
      portHandler,
      1,
      2,     // ADDR_DRIVE_MODE
      &results32
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Model Information." << std::endl;
    } else {
      std::cout << "Succeeded to read Model Information." << std::endl;
      //print model information
      std::cout << "Model Information Version: " << results32 << std::endl;
    }


    dxl_comm_result = packetHandler->read1ByteTxRx(
      portHandler,
      1,
      6,     // ADDR_DRIVE_MODE
      &result8
    );
    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Firmware Version." << std::endl;
    } else {
      std::cout << "Succeeded to read Firmware Version." << std::endl;
      //print firmware version
      std::cout << "Firmware Version: " << static_cast<int>(result8) << std::endl;
    }

    dxl_comm_result = packetHandler->read1ByteTxRx(
      portHandler,
      1,
      7,     // ADDR_DRIVE_MODE
      &result8
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read ID." << std::endl;
    } else {
      std::cout << "Succeeded to read ID." << std::endl;
      //print ID
      std::cout << "ID: " << static_cast<int>(result8) << std::endl;
    }


    dxl_comm_result = packetHandler->read1ByteTxRx(
      portHandler,
      1,
      8,     // ADDR_DRIVE_MODE
      &result8
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Baud Rate." << std::endl;
    } else {
      std::cout << "Succeeded to read Baud Rate." << std::endl;
      //print baud rate
      std::cout << "Baud Rate: " << static_cast<int>(result8) << std::endl;
    }


    dxl_comm_result = packetHandler->read1ByteTxRx(
      portHandler,
      1,
      9,     // ADDR_DRIVE_MODE
      &result8
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Return Delay Time." << std::endl;
    } else {
      std::cout << "Succeeded to read Return Delay Time." << std::endl;
      //print return delay time
      std::cout << "Return Delay Time: " << static_cast<int>(result8) << std::endl;
    }

    dxl_comm_result = packetHandler->read1ByteTxRx(
      portHandler,
      1,
      10,     // ADDR_DRIVE_MODE
      &result8
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Drive Mode." << std::endl;
    } else {
      std::cout << "Succeeded to read Drive Mode." << std::endl;
      //print drive mode
      std::cout << "Drive Mode: " << static_cast<int>(result8) << std::endl;
    }

    dxl_comm_result = packetHandler->read1ByteTxRx(
      portHandler,
      1,
      11,     // ADDR_DRIVE_MODE
      &result8
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Operating Mode." << std::endl;
    } else {
      std::cout << "Succeeded to read Operating Mode." << std::endl;
      //print operating mode
      std::cout << "Operating Mode: " << static_cast<int>(result8) << std::endl;
    }
    
    dxl_comm_result = packetHandler->read1ByteTxRx(
      portHandler,
      1,
      12,     // ADDR_DRIVE_MODE
      &result8
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Secondary Shadow ID." << std::endl;
    } else {
      std::cout << "Succeeded to read Secondary Shadow ID." << std::endl;
      //print secondary shadow ID
      std::cout << "Secondary Shadow ID: " << static_cast<int>(result8) << std::endl;
    }

    dxl_comm_result = packetHandler->read1ByteTxRx(
      portHandler,
      1,
      13,     // ADDR_DRIVE_MODE
      &result8
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Protocol Type." << std::endl;
    } else {
      std::cout << "Succeeded to read Protocol Type." << std::endl;
      //print protocol type
      std::cout << "Protocol Type: " << static_cast<int>(result8) << std::endl;
    }

    dxl_comm_result = packetHandler->read4ByteTxRx(
      portHandler,
      1,
      20,     // ADDR_DRIVE_MODE
      &results32
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Homing Offset." << std::endl;
    } else {
      std::cout << "Succeeded to read Homing Offset." << std::endl;
      //print homing offset
      std::cout << "Homing Offset: " << results32 << std::endl;
    }

    dxl_comm_result = packetHandler->read4ByteTxRx(
      portHandler,
      1,
      24,     // ADDR_DRIVE_MODE
      &results32
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Moving Threshold." << std::endl;
    } else {
      std::cout << "Succeeded to read Moving Threshold." << std::endl;
      //print moving threshold
      std::cout << "Moving Threshold: " << results32 << std::endl;
    }

    dxl_comm_result = packetHandler->read1ByteTxRx(
      portHandler,
      1,
      31,     // ADDR_DRIVE_MODE
      &result8
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Temperature Limit." << std::endl;
    } else {
      std::cout << "Succeeded to read Temperature Limit." << std::endl;
      //print temperature limit
      std::cout << "Temperature Limit: " << static_cast<int>(result8) << std::endl;
    }

    dxl_comm_result = packetHandler->read2ByteTxRx(
      portHandler,
      1,
      32,     // ADDR_DRIVE_MODE
      &result16
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Max Voltage Limit." << std::endl;
    } else {
      std::cout << "Succeeded to read Max Voltage Limit." << std::endl;
      //print max voltage limit
      std::cout << "Max Voltage Limit: " << result16 << std::endl;
    }

    dxl_comm_result = packetHandler->read2ByteTxRx(
      portHandler,
      1,
      34,     // ADDR_DRIVE_MODE
      &result16
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Min Velocity Limit." << std::endl;
    } else {
      std::cout << "Succeeded to read Min Velocity Limit." << std::endl;
      //print min velocity limit
      std::cout << "Min Velocity Limit: " << result16 << std::endl;
    }

    dxl_comm_result = packetHandler->read2ByteTxRx(
      portHandler,
      1,
      36,     // ADDR_DRIVE_MODE
      &result16
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read PWM Limit." << std::endl;
    } else {
      std::cout << "Succeeded to read PWM Limit." << std::endl;
      //print PWM limit
      std::cout << "PWM Limit: " << result16 << std::endl;
    }

    dxl_comm_result = packetHandler->read4ByteTxRx(
      portHandler,
      1,
      44,     // ADDR_DRIVE_MODE
      &results32
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Max Velocity Limit." << std::endl;
    } else {
      std::cout << "Succeeded to read Max Velocity Limit." << std::endl;
      //print max velocity limit
      std::cout << "Max Velocity Limit: " << results32 << std::endl;
    }

    dxl_comm_result = packetHandler->read4ByteTxRx(
      portHandler,
      1,
      48,     // ADDR_DRIVE_MODE
      &results32
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Max Position Limit." << std::endl;
    } else {
      std::cout << "Succeeded to read Max Position Limit." << std::endl;
      //print max position limit
      std::cout << "Max Position Limit: " << results32 << std::endl;
    }

    dxl_comm_result = packetHandler->read4ByteTxRx(
      portHandler,
      1,
      52,     // ADDR_DRIVE_MODE
      &results32
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Min Position Limit." << std::endl;
    } else {
      std::cout << "Succeeded to read Min Position Limit." << std::endl;
      //print min position limit
      std::cout << "Min Position Limit: " << results32 << std::endl;
    }

    dxl_comm_result = packetHandler->read1ByteTxRx(
      portHandler,
      1,
      60,     // ADDR_DRIVE_MODE
      &result8
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Startup Configuration." << std::endl;
    } else {
      std::cout << "Succeeded to read Startup Configuration." << std::endl;
      //print startup configuration
      std::cout << "Startup Configuration: " << static_cast<int>(result8) << std::endl;
    }

    dxl_comm_result = packetHandler->read1ByteTxRx(
      portHandler,
      1,
      63,     // ADDR_DRIVE_MODE
      &result8
    );

    if (dxl_comm_result != COMM_SUCCESS) {
      std::cerr << "Failed to read Shutdown." << std::endl;
    } else {
      std::cout << "Succeeded to read Shutdown." << std::endl;
      //print shutdown
      std::cout << "Shutdown: " << static_cast<int>(result8) << std::endl;
    }


    // Keep the port open briefly to allow manual inspection if needed
    std::cout << "Port open. Reading register map then sleeping 1s then closing." << std::endl;
    readRegisterMap(portHandler, packetHandler, 1);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    if (portHandler && portHandler->is_using_) {
      portHandler->closePort();
      std::cout << "Port closed." << std::endl;
    }
    return 0;
}

// Table-driven reader: address, size(in bytes), label, access, range
struct RegEntry {
  uint16_t addr;
  uint8_t size;
  const char *label;
  const char *access;
  const char *range;
};

static void readRegisterMap(dynamixel::PortHandler *portHandler, dynamixel::PacketHandler *packetHandler, uint8_t dxl_id)
{
  RegEntry regs[] = {
    {64,  1,  "Torque Enable", "RW", "0 ~ 1"},
    {65,  1,  "LED", "RW", "0 ~ 1"},
    {68,  1,  "Status Return Level", "RW", "0 ~ 2"},
    {69,  1,  "Registered Instruction", "R", "0 ~ 1"},
    {70,  1,  "Hardware Error Status", "R", "-"},
    {76,  2,  "Velocity I Gain", "RW", "0 ~ 16383"},
    {78,  2,  "Velocity P Gain", "RW", "0 ~ 16383"},
    {80,  2,  "Position D Gain", "RW", "0 ~ 16383"},
    {82,  2,  "Position I Gain", "RW", "0 ~ 16383"},
    {84,  2,  "Position P Gain", "RW", "0 ~ 16383"},
    {88,  2,  "Feedforward 2nd Gain", "RW", "0 ~ 16383"},
    {90,  2,  "Feedforward 1st Gain", "RW", "0 ~ 16383"},
    {98,  1,  "Bus Watchdog", "RW", "1 ~ 127"},
    {100, 2,  "Goal PWM", "RW", "-PWM Limit(36) ~"},
    {104, 4,  "Goal Velocity", "RW", "-Velocity Limit(44) ~"},
    {108, 4,  "Profile Acceleration", "RW", "0 ~ 32767"},
    {112, 4,  "Profile Velocity", "RW", "0 ~ 32767"},
    {116, 4,  "Goal Position", "RW", "Min Position Limit(52) ~ Max Position Limit(48)"},
    {120, 2,  "Realtime Tick", "R", "0 ~ 32767"},
    {122, 1,  "Moving", "R", "0 ~ 1"},
    {123, 1,  "Moving Status", "R", "-"},
    {124, 2,  "Present PWM", "R", "-"},
    {126, 2,  "Present Load", "R", "-1000 ~ 1000"},
    {128, 4,  "Present Velocity", "R", "-"},
    {132, 4,  "Present Position", "R", "-"},
    {136, 4,  "Velocity Trajectory", "R", "-"},
    {140, 4,  "Position Trajectory", "R", "-"},
    {144, 2,  "Present Input Voltage", "R", "-"},
    {146, 1,  "Present Temperature", "R", "-"},
    {147, 1,  "Backup Ready", "R", "0 ~ 1"},
    {168, 2,  "Indirect Address 1", "RW", "64 ~ 661"},
    {170, 2,  "Indirect Address 2", "RW", "64 ~ 661"},
    {172, 2,  "Indirect Address 3", "RW", "64 ~ 661"},
    {218, 2,  "Indirect Address 26", "RW", "64 ~ 661"},
    {220, 2,  "Indirect Address 27", "RW", "64 ~ 661"},
    {222, 2,  "Indirect Address 28", "RW", "64 ~ 661"},
    {224, 1,  "Indirect Data 1", "RW", "0 ~ 255"},
    {225, 1,  "Indirect Data 2", "RW", "0 ~ 255"},
    {226, 1,  "Indirect Data 3", "RW", "0 ~ 255"},
    {249, 1,  "Indirect Data 26", "RW", "0 ~ 255"},
    {250, 1,  "Indirect Data 27", "RW", "0 ~ 255"},
    {251, 1,  "Indirect Data 28", "RW", "0 ~ 255"},
    {578, 2,  "Indirect Address 29", "RW", "64 ~ 661"},
    {580, 2,  "Indirect Address 30", "RW", "64 ~ 661"},
    {582, 2,  "Indirect Address 31", "RW", "64 ~ 661"},
    {628, 2,  "Indirect Address 54", "RW", "64 ~ 661"},
    {630, 2,  "Indirect Address 55", "RW", "64 ~ 661"},
    {632, 2,  "Indirect Address 56", "RW", "64 ~ 661"},
    {634, 1,  "Indirect Data 29", "RW", "0 ~ 255"},
    {635, 1,  "Indirect Data 30", "RW", "0 ~ 255"},
    {636, 1,  "Indirect Data 31", "RW", "0 ~ 255"},
    {659, 1,  "Indirect Data 54", "RW", "0 ~ 255"},
    {660, 1,  "Indirect Data 55", "RW", "0 ~ 255"},
    {661, 1,  "Indirect Data 56", "RW", "0 ~ 255"}
  };

  const size_t n = sizeof(regs) / sizeof(regs[0]);
  std::cout << "\nReading register map (id=" << static_cast<int>(dxl_id) << "):\n";
  for (size_t i = 0; i < n; ++i) {
    const RegEntry &r = regs[i];
    int comm_res = COMM_TX_FAIL;
    if (r.size == 1) {
      uint8_t v8 = 0;
      comm_res = packetHandler->read1ByteTxRx(portHandler, dxl_id, r.addr, &v8);
      if (comm_res == COMM_SUCCESS) {
        std::cout << r.addr << "\t1\t" << r.label << "\t" << r.access << "\t" << r.range << "\tValue=" << static_cast<int>(v8) << "\n";
      } else {
        std::cout << r.addr << "\t1\t" << r.label << "\t" << r.access << "\tERROR (comm=" << comm_res << ")\n";
      }
    } else if (r.size == 2) {
      uint16_t v16 = 0;
      comm_res = packetHandler->read2ByteTxRx(portHandler, dxl_id, r.addr, &v16);
      if (comm_res == COMM_SUCCESS) {
        std::cout << r.addr << "\t2\t" << r.label << "\t" << r.access << "\t" << r.range << "\tValue=" << v16 << "\n";
      } else {
        std::cout << r.addr << "\t2\t" << r.label << "\t" << r.access << "\tERROR (comm=" << comm_res << ")\n";
      }
    } else if (r.size == 4) {
      uint32_t v32 = 0;
      comm_res = packetHandler->read4ByteTxRx(portHandler, dxl_id, r.addr, &v32);
      if (comm_res == COMM_SUCCESS) {
        std::cout << r.addr << "\t4\t" << r.label << "\t" << r.access << "\t" << r.range << "\tValue=" << v32 << "\n";
      } else {
        std::cout << r.addr << "\t4\t" << r.label << "\t" << r.access << "\tERROR (comm=" << comm_res << ")\n";
      }
    } else {
      std::cout << r.addr << "\t" << static_cast<int>(r.size) << "\t" << r.label << "\t" << r.access << "\tUnsupported size\n";
    }
  }
  std::cout << std::endl;
}
