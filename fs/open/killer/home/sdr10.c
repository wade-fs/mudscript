inherit ROOM;

void create ()
{
set("short","殺手地下訓練場 C 區");
  set ("long", @LONG
這裡是殺手總壇的地下迷宮，也是由機關手諸岡渡所精心設置。
尋常人並無法輕易的離開此處，或許應該小心一點，
但是這裡也是頂尖殺手自我訓練的好地方。
這裡的殺氣似乎更盛了，如果沒有兩把刷子，最好離開這裡。
此處都是黑牙聯的超級高手，如果你不夠強的話最好不要找死。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"sdr14.c",
"east" : __DIR__"sdr6.c",
"south" : __DIR__"sdr11.c",
"north" : __DIR__"sdr9.c",
]));
set("objects",([
"/open/killer/npc/sdkillc.c":2,
]));
  setup();
}
