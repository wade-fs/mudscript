inherit ROOM;

void create ()
{
  set ("short", "聖火祕密集會中心");
  set ("long", @LONG

    這裡是聖火教眾們集會的場所,在這裡,你可享受到外面
所沒有的言論自由及人身安全,同時你也可將收集來的eq置
放在這,給後進晚輩一些貼心的關懷..:)

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "down" :"/open/prayer/room/punch1.c",
]));

  set("light_up", 1);
  set("no_clean_up",1);
  set("no_fight",1);
  setup();
  call_other("/obj/board/prayersss_b","????");
}
