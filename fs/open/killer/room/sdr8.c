inherit ROOM;

void create ()
{
set("short","殺手地下訓練場 B 區");
  set ("long", @LONG
這裡是殺手總壇的地下迷宮，也是由機關手諸岡渡所精心設置。
尋常人並無法輕易的離開此處，或許應該小心一點，
因為四周傳來的殺氣，正訴說著此處所佈滿的危機。
但是這裡也是頂尖殺手自我訓練的好地方。
這裡的殺氣似乎更盛了，如果沒有兩把刷子，最好離開這裡。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"sdr12.c",
"east" : __DIR__"sdr4.c",
"north" : __DIR__"sdr7.c",
]));
set("objects",([
"/open/killer/npc/sdkillb.c":2,
]));
  setup();
}
