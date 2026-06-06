// Room: /open/gsword/room/school.c

inherit ROOM;

void create ()
{
  set ("short", "私塾");
  set ("long", @LONG
這裡是一家私塾,蜀中市民大都是在此完成他們的學業,你聽到學童
朗朗的讀書聲,也讓你想起你的求學生涯,不也那麼天真,可愛.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/gsword/room/su10",
]));

  set("objects",([
  "/open/gsword/npc/teacher" : 1,
   ]));
  set("light_up", 1);

  setup();
}
