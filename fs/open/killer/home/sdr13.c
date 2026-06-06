inherit ROOM;

void create ()
{
set("short","殺手地下訓練場 D 區");
  set ("long", @LONG
這裡是殺手總壇的地下迷宮，也是由機關手諸岡渡所精心設置。
尋常人並無法輕易的離開此處，或許應該小心一點，
此處都是黑牙聯的超級高手，如果你不夠強的話最好不要找死。
此處的高手，有些人的實戰經驗並非你能想像的高，所以你還是小心的好。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
"east" : __DIR__"sdr9.c",
"south" : __DIR__"sdr14.c",
]));
set("objects",([
"/open/killer/npc/sdkilld.c":1,
]));
  setup();
}
