#pragma once

#include <string>



enum class EraseMode
{
	UntilEnd,
	UntilStart,
	Full,

	// erase display only
	FullAndEraseBuffer
};



// default control sequence introducer
const std::string CSI = "\x1b";
const std::string CCSI = "\x1b[";



inline std::string cursorUp(const unsigned int n)       noexcept { return CCSI + std::to_string(n) + "A"; }
inline std::string cursorDown(const unsigned int n)     noexcept { return CCSI + std::to_string(n) + "B"; }
inline std::string cursorForward(const unsigned int n)  noexcept { return CCSI + std::to_string(n) + "C"; }
inline std::string cursorBack(const unsigned int n)     noexcept { return CCSI + std::to_string(n) + "D"; }
inline std::string cursorUpLine(const unsigned int n)   noexcept { return CCSI + std::to_string(n) + "F"; }
inline std::string cursorDownLine(const unsigned int n) noexcept { return CCSI + std::to_string(n) + "E"; }
inline std::string cursorToColumn(const unsigned int n) noexcept { return CCSI + std::to_string(n) + "G"; }

inline std::string cursorTo(const unsigned int row, const unsigned int col) noexcept
{
	return CCSI + std::to_string(row) + ";" + std::to_string(col) + "H";
}

inline std::string cursorToHome() noexcept { return cursorTo(0, 0); }

inline std::string saveCursorPosition() noexcept { return CCSI + "s"; }
inline std::string loadCursorPosition() noexcept { return CCSI + "u"; }



inline std::string eraseDisplay(const EraseMode mode) noexcept
{
	return CCSI + std::to_string((unsigned int)mode) + "J";
}

inline std::string eraseLine(const EraseMode mode) noexcept
{
	return CCSI + std::to_string((unsigned int)mode) + "K";
}
