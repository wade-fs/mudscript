// Room: /open/bonze/room/k06
inherit ROOM;

void create ()
{
  set ("short", "休息室");
  set ("long", @LONG
這裡是伙房師父休息的地方，你看到幾位師父已經開始打坐了，並
且內力充滿全身，少林寺就是這樣，只要經過認可，每個人都可以練功
。到了這裡，你最好不要打擾他們。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"k04.c",
]));
  set("no_magic", 1);
  set("no_fight", 1);
  set("light_up", 1);

  setup();
}
