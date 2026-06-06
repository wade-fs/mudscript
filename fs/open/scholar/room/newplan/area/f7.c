// Room: /u/s/sueplan/newplan/area/f7.c
inherit ROOM;

void create ()
{
  set ("short", "樹道");
  set ("long", @LONG
你步行於此，道路兩旁青翠樹木排列整齊，列行相對，頻頻映青，形成
濃濃的樹蔭，當微風輕彿而過，在炎炎夏日當中帶了幾分的涼爽，消除了夏
日所帶了的暑氣，當為秋天之時，道路兩旁數目爰首穡，落葉繽紛之際，頗
有蕭然虛清之美，此處往南行走，可到達名山雲山。
LONG);

  set("outdoors", "/u/s");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"f8.c",
  "west" : __DIR__"f6",
]));

  setup();
}
