# UART Lowercase to Uppercase Converter

This application demonstrates basic UART communication on an STM32 microcontroller. It receives a string of characters from a PC terminal, converts any lowercase letters to uppercase, and sends the processed string back to the PC.

## ⚙️ Configuration & Settings

Correct terminal configuration is essential for successful communication.

### 1. Serial Port Settings
The UART2 peripheral is configured to operate at **9600 baud rate** in the firmware.
* **Port:** COM6 (Depending on your system)
* **Speed:** 9600 bps
* **Data:** 8 bit
* **Parity:** none
* **Stop bits:** 1 bit
* **Flow control:** none

![Tera Term Serial Port Settings](Images/TeraTerm_Settings_2.png)

### 2. Terminal Settings
**Local echo** must be enabled in Tera Term to see the characters you type before they are sent to the MCU.
* **Receive:** CR+LF (Carriage Return + Line Feed)
* **Transmit:** CR (Carriage Return)
* **Local echo:** Checked (Enabled)

![Tera Term Terminal Settings](Images/TeraTerm_Settings_1.png)

---

## 📊 Test Results & Verification

### Terminal Output
Upon reset, the application transmits the start message: `"The application is running"`.
It then waits for user input. In this test, the input string `"upper case test"` was typed and sent by pressing Enter. The MCU successfully received the data, converted it, and transmitted back `"UPPER CASE TEST"`.

![Tera Term Output](Images/TeraTerm_Output.png)

### Logic Analyzer Signal View
The physical signal on the UART TX line (Channel D0) during the transmission of the initial message is captured below. This verifies the correct baud rate and frame format at the hardware level.

![Logic Analyzer Output](Images/LogicAnalyzer_Output.png)

---

## 📝 Firmware Overview

* **`main()`**: Initializes the system and UART2. Sends a welcome message in blocking mode. Enters a loop to receive characters one by one until a Carriage Return (`\r`) is detected.
* **`UART2_Init()`**: Configures USART2 instance with 9600 baud rate, 8-bit word length, 1 stop bit, and no parity.
* **`convert_to_capital(uint8_t data)`**: A helper function that checks if the received ASCII character is between 'a' and 'z'. If so, it subtracts 32 to convert it to its uppercase ASCII equivalent.
