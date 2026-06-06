inherit ROOM;

void create ()
{
  set ("short","東院走廊");
  set ("long", @LONG
走到這裡,忽然覺得有一股清風吹來,讓人心曠神怡,環顧四周,看到莊
嚴雄偉的大雄寶殿,使你由衷地想進去參拜一下。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"aa27",
  "south" : __DIR__"aa22",
]));
}
