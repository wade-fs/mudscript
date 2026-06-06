#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "樹叢小徑");
  set ("long", @LONG
你感覺似乎走了好久，剛剛看到的那座塔就在不遠的地方啦！你發覺這四週的
花草樹木已不像剛剛那些地方那樣濃密了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road2",
  "east" : __DIR__"road4",
]));
set("objects", ([ /* sizeof() == 1 */
  "/open/tendo/room/tower/npc/su" : 1,
]));
  set("outdoors", 1);
  set("no_smash",1);
  set("no_dest",1);
  setup();
}
int valid_leave(object me, string dir) {
  if(dir=="east"&&present("elder su",environment(me))) {
  return notify_fail("蘇星河大叫：想過去！先殺了我再說吧!!\n");
  } 
 return 1;
}
void init()
{
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
        call_out( "death_stage", 1, previous_object());
}

void death_stage(object ob)
{
        if( !ob || !present(ob) ) return;
        if ( ob->query("combat_exp") < 450000 ){
                message_vision(HIW + "\n\t你突然感覺到一陣迫人的氣息!\n" + NOR,ob,environment());
                message_vision(HIW + "     －－由於你的經驗不足，所以被蘇星河的內力震了出來－－\n\n" + NOR,ob,environment());
                ob->move(__DIR__"road2.c");
        }
        call_out("death_stage", 1, ob);
}



