#include <cstdio>
#include <string>
#include <fmt/core.h>
using namespace std;

  string Reset = "\033[0m"; // Reset / Normal	all attributes off
  string Bold ="\033[1m"; // Bold or increased intensity
  string Faint ="\033[2m"; // Faint (decreased intensity)	Not widely supported.
  string Italic ="\033[3m"; // Italic	Not widely supported. Sometimes treated as inverse.
  string Underline ="\033[4m"; // Underline
  string SlowBlink ="\033[5m"; // Slow Blink	less than 150 per minute
  string RapidBlink ="\033[6m"; // Rapid Blink	MS-DOS ANSI.SYS; 150+ per minute; not widely supported
  string SwapFgBg ="\033[7m"; // [[reverse video]]	swap foreground and background colors
  string Conceal ="\033[8m"; // Conceal	Not widely supported.
  string CrossedOut ="\033[9m"; // Crossed-out	Characters legible, but marked for deletion. Not widely supported.
  string Primary ="\033[10m"; // Primary(default) font
  string AlternateFont ="\033[11m"; // –19	Alternate font	Select alternate font n-10
  string Fraktur ="\033[20m"; // Fraktur	hardly ever supported
  string BoldOffDoubleUnderline ="\033[21m"; // Bold off or Double Underline	Bold off not widely supported; double underline hardly ever supported.
  string NormalColor ="\033[22m"; // Normal color or intensity	Neither bold nor faint
  string NotItalicNotFraktur ="\033[23m"; // Not italic, not Fraktur
  string UnderlineOff ="\033[24m"; // Underline off	Not singly or doubly underlined
  string BlinkOff ="\033[25m"; // Blink off
  string InverseOff ="\033[27m"; // Inverse off
  string Reveal ="\033[28m"; // Reveal	conceal off
  string NotCrossedOut ="\033[29m"; // Not crossed out
  string SetFgColor ="\033[30m"; // –37	Set foreground color	See color table below
  string SetFgColorArgs ="\033[38m"; // Set foreground color	Next arguments are 5;<n> or 2;<r>;<g>;<b>, see below
  string DefaultFgColor ="\033[39m"; // Default foreground color	implementation defined (according to standard)
  string SetBgColor ="\033[40m"; // –47	Set background color	See color table below
  string SetBgColorArgs ="\033[48m"; // Set background color	Next arguments are 5;<n> or 2;<r>;<g>;<b>, see below
  string DefaultBgColor ="\033[49m"; // Default background color	implementation defined (according to standard)
  string Framed ="\033[51m"; // Framed
  string Encircled ="\033[52m"; // Encircled
  string Overlined ="\033[53m"; // Overlined
  string NotFramedEncircled ="\033[54m"; // Not framed or encircled
  string NotOverlined ="\033[55m"; // Not overlined
  string IdeogramUnderline ="\033[60m"; // ideogram underline	hardly ever supported
  string IdeogramDoubleUnderline ="\033[61m"; // ideogram double underline	hardly ever supported
  string IdeogramOverline ="\033[62m"; // ideogram overline	hardly ever supported
  string IdeogramDoubleOverline ="\033[63m"; // ideogram double overline	hardly ever supported
  string IdeogramStressMarking ="\033[64m"; // ideogram stress marking	hardly ever supported
  string IdeogramAttributesOff ="\033[65m"; // ideogram attributes off	reset the effects of all of 60-64
  string SetBrightFgColor="\033[90m"; // –97	Set bright foreground color	aixterm (not in standard)
  string SetBrightBgColor ="\033[100m";// –107	Set bright background color	aixterm (not in standard)

int main(int argc, char const *argv[]) {
  fmt::print("Ansi color escape\n");
  fmt::print("\033[1mHello, World\033[0m\n");
  fmt::print("\033[2mHello, World\033[0m\n");
  fmt::print("\033[3mHello, World\033[0m\n");
  fmt::print("\033[4mHello, World\033[0m\n");
  fmt::print("\033[5mHello, World\033[0m\n");
  fmt::print("\033[7mHello, World\033[0m\n");
  fmt::print("\033[9mHello, World\033[0m\n");
  fmt::print("\033[21mHello, World\033[0m\n\n");

  fmt::print("2-bit Colours\n");
  fmt::print("\033[0;31mHello, World\033[0m\n");
  fmt::print("\033[30;31mHello, World\033[0m\n");
  fmt::print("\033[40;31mHello, World\033[0m\n\n");
  
  fmt::print("4-bit Colours\n");
  fmt::print("\033[31;107mHello, World\033[0m\n\n");

  fmt::print("8-bit (256) colours\n"); 
  fmt::print("\033[38;5;9mHello, World\033[0m\n");
  fmt::print("\033[48;5;9mHello, World\033[0m\n");
  fmt::print("\033[38;5;9;48;5;11mHello, World\033[0m\n");
  fmt::print("\033[38;2;100;100;255;48;2;1;2;3mHello, World\033[0m\n");

  fmt::print("\n\033[5;38;5;34;48;5;226mANSI COLOR ESCAPE\033[0m\n");

  return 0;
}
