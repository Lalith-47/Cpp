#pragma once

// ======================
// ANSI Text Styles
// ======================
#define reset "\033[0m"
#define bold "\033[1m"
#define dim "\033[2m"
#define italic "\033[3m"
#define underline "\033[4m"
#define blink "\033[5m"
#define reverse "\033[7m"
#define hidden "\033[8m"
#define strike "\033[9m"

// ======================
// ANSI Foreground Colors
// ======================
#define black "\033[30m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define blue "\033[34m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define white "\033[37m"

// Bright Foreground Colors
#define bblack "\033[90m"
#define bred "\033[91m"
#define bgreen "\033[92m"
#define byellow "\033[93m"
#define bblue "\033[94m"
#define bmagenta "\033[95m"
#define bcyan "\033[96m"
#define bwhite "\033[97m"

// ======================
// ANSI Background Colors
// ======================
#define bg_black "\033[40m"
#define bg_red "\033[41m"
#define bg_green "\033[42m"
#define bg_yellow "\033[43m"
#define bg_blue "\033[44m"
#define bg_magenta "\033[45m"
#define bg_cyan "\033[46m"
#define bg_white "\033[47m"

// Bright Background Colors
#define bg_bblack "\033[100m"
#define bg_bred "\033[101m"
#define bg_bgreen "\033[102m"
#define bg_byellow "\033[103m"
#define bg_bblue "\033[104m"
#define bg_bmagenta "\033[105m"
#define bg_bcyan "\033[106m"
#define bg_bwhite "\033[107m"

// ======================
// Common Unicode / Emoji Shortcuts
// ======================
// Status
#define tick u8"\u2705"     // ✅
#define cross u8"\u274C"    // ❌
#define warn u8"\u26A0"     // ⚠
#define info u8"\u2139"     // ℹ
#define question u8"\u2753" // ❓
#define loading u8"\u23F3"  // ⏳
#define done u8"\u2714"     // ✔
#define fail u8"\u2716"     // ✖

// Symbols
#define star u8"\u2B50"             // ⭐
#define sparkle u8"\u2728"          // ✨
#define fire u8"\U0001F525"         // 🔥
#define heart u8"\u2764"            // ❤️
#define broken_heart u8"\U0001F494" // 💔
#define rocket u8"\U0001F680"       // 🚀
#define bulb u8"\U0001F4A1"         // 💡
#define globe u8"\U0001F310"        // 🌐
#define paperclip u8"\U0001F4CE"    // 📎
#define pin u8"\U0001F4CC"          // 📌
#define lock u8"\U0001F512"         // 🔒
#define unlock u8"\U0001F513"       // 🔓
#define bell u8"\U0001F514"         // 🔔
#define mute u8"\U0001F507"         // 🔇

// Objects
#define laptop u8"\U0001F4BB"  // 💻
#define phone u8"\U0001F4F1"   // 📱
#define battery u8"\U0001F50B" // 🔋
#define plug u8"\U0001F50C"    // 🔌
#define chip u8"\U0001F9E9"    // 🧩
#define gear u8"\u2699"        // ⚙
#define wrench u8"\U0001F527"  // 🔧
#define hammer u8"\U0001F528"  // 🔨

#define coffee u8"\u2615"     // ☕
#define pizza u8"\U0001F355"  // 🍕
#define burger u8"\U0001F354" // 🍔
#define cake u8"\U0001F382"   // 🎂

#define clock u8"\u23F0"          // ⏰
#define calendar u8"\U0001F4C5"   // 📅
#define book u8"\U0001F4D6"       // 📖
#define memo u8"\U0001F4DD"       // 📝
#define chart_up u8"\U0001F4C8"   // 📈
#define chart_down u8"\U0001F4C9" // 📉

// Faces
#define smile u8"\U0001F604"     // 😄
#define grin u8"\U0001F601"      // 😁
#define wink u8"\U0001F609"      // 😉
#define laugh u8"\U0001F606"     // 😆
#define cool u8"\U0001F60E"      // 😎
#define cry u8"\U0001F622"       // 😢
#define angry u8"\U0001F620"     // 😠
#define surprised u8"\U0001F62E" // 😮
#define thinking u8"\U0001F914"  // 🤔

// Currency symbols
#define dollar u8"$"     // US Dollar $
#define euro u8"\u20AC"  // Euro €
#define yen u8"\u00A5"   // Japanese Yen ¥
#define pound u8"\u00A3" // British Pound £
#define btc u8"\u20BF"   // Bitcoin ₿
#define aud u8"A$"       // Australian Dollar
#define cad u8"C$"       // Canadian Dollar
#define yuan u8"\u5143"  // Chinese Yuan 元
#define won u8"\u20A9"   // South Korean Won ₩
#define rub u8"\u20BD"   // Russian Ruble ₽
#define lira u8"\u20BA"  // Turkish Lira ₺

// Cursor Movement Macros
#define up(n) "\033[" #n "A"
#define down(n) "\033[" #n "B"
#define forward(n) "\033[" #n "C"
#define back(n) "\033[" #n "D"
#define clr "\033[K"
#define cls "\033[2J"
#define home "\033[H"
#define hide "\033[?25l"
#define show "\033[?25h"