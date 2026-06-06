#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIW + "天樞樓" + NOR);
	set( "build", 44 );
  set ("long", @LONG
這是七星塔中的最後一層, 看了看四周, 心中深感不可思議,
周圍盡是一堆堆的白骨, 白骨旁散落著一堆堆的武器及裝備, 你
正打算將功力凝聚到十成時, 樓主已經衝到你的身邊, 以下了重
手,令你此時不知所措。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/gsword/room/g5-1.c",
  //"out" : __DIR__"room1.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star2.c" : 1,
]));

  setup();
}
void init()
{
        add_action("do_search", "search");
        add_action("do_jump","jump");
	add_action("do_enter","enter");
}

int do_jump(string str){
 int exp;  
 object me;
 string name;
 me = this_player();
 exp=me->query("combat_exp",1);
 name=me->query("name");

	if(!str || str != "hole")
	{
        tell_object(me,"你想跳到那裡？\n");
	return 1;
        }
	if(present("starman",environment(me)))
	{
        if(me)
        tell_object(me,HIY + "鬼宿說：還沒打敗我就想去那裏呢？\n" + NOR);
        return 0;
	}
	if(exp < 340000)
	{
        tell_object(me,"你經驗值不夠，進入魔界也是徒然送死。\n");
        return 0;
        }
        tell_object(me,"你縱身跳進這黑色的漩渦，頓時神智昏迷，迷迷糊糊中被傳到某一地方.....。\n");
        tell_object(users(),HIB + "
                   風蕭蕭兮易水寒～～
                                     壯士一去兮不復還～～         

      " + HIM + "七星塔頂烏雲密佈，魔界的入口漸漸浮現..."+HIY+name+HIM + "毅然踏上了遠征
      魔界的路途，誓言以自身之絕世武功剷平魔界所有危害人類的妖怪...
                   
" + NOR);

            me->move("/open/mogi/forest/room1");
            return 1;

            
}

int do_enter(string str)
{
   object me = this_player();
  if(me->query("liyu")==2)
   me->move("/open/gsword/room/appo/liyu.c");
   return 1;
}

int do_search()
{
	object me;
	me = this_player();
	tell_object(me,"你找啊找，終於在牆上發現一個黑色的漩渦(hole)，怪詭異的，跳(jump)進去不知會到那裡?\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	if( dir=="up" && present("starman",environment(me)))
	return notify_fail(HIY + "鬼宿說：還沒打敗我就想去那裏呢？\n" + NOR);
	return ::valid_leave(me,dir);

}
