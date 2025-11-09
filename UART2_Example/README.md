# UART Lowercase to Uppercase Converter

This application receives characters from a PC via UART on an STM32 microcontroller, converts lowercase letters to uppercase, and sends the processed string back to the PC.

## ⚙️ Configuration & Settings

Correct terminal configuration is essential for successful communication.

### 1\. Serial Port Settings

The project is configured to operate at **9600 baud rate**.

  * **Port:** COM6 
  * **Speed:** 9600 bps
  * **Data:** 8 bit
  * **Parity:** none
  * **Stop bits:** 1 bit
  * **Flow control:** none

### 2\. Terminal Settings

**Local echo** must be enabled to see transmitted characters on the screen.

  * **Receive:** CR+LF (Carriage Return + Line Feed)
  * **Transmit:** CR (Carriage Return)
  * **Local echo:** Checked (Enabled)

-----

## 📊 Test Results

### Terminal Output

Upon starting, the application sends the message "The application is running". It then waits for user input. The input string "upper case test" is received by the MCU, converted to "UPPER CASE TEST", and transmitted back.

### Logic Analyzer Signal View

The physical signal changes on the UART transmission line (Channel D0) during data transfer are shown below.

-----

## 📝 Code Overview

  * **`main()`**: Initializes HAL, system clock, and UART2. Sends a welcome message, then enters a loop to receive characters until a Carriage Return ('\\r') is detected. Each received character is converted to uppercase and stored in a buffer. Finally, the converted string is transmitted back.
  * **`UART2_Init()`**: Configures USART2 with 9600 baud rate, 8 data bits, 1 stop bit, and no parity.
  * **`convert_to_capital()`**: Helper function that checks if a character is a lowercase letter ('a'-'z') and converts it to its uppercase equivalent by subtracting 32 from its ASCII value.
