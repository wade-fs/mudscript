//written by acelan...../u/a/acelan/room/wood20.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "神木之頂");
        set("long", @LONG
神木之頂比你想像的還要高很多, 到此依舊林木茂密, 往上更是
黑壓壓的一大片, 看起來頗為不自然, 似乎是故意在掩蔽些什麼, 而
在前方隱密處, 隱約有條繩子(rope), 不知道是做什麼用的。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "down" : "/open/killer/mon/room/wood19.c",
       "east" : "/open/killer/mon/room/wood21.c",
   ]));
   set("item_desc", ([
       "rope" : "這是一條很普通的繩子, 不知為何垂在這裡。\n",
   ]));
   set("search_desc", ([
       "rope" : "你仔細觀察這條繩子後, 發現它是連接到上方的一塊木板處, 你可以試著拉拉看(pull)。\n",
   ]));
   set("no_clean_up", 0);

   setup();
}

void init()
{
   add_action("do_pull", "pull");
}

int do_pull( string arg)
{
   object me, killer;
   me= this_player();
   if( arg != "rope")
   {
      message_vision("你拉呀拉的, 拉了老半天, 終於給你拉下了一根神木的樹枝, 可以帶回家做紀念。\n", me);
      return 0;
   }
   message_vision("你用力的拉下了繩子, 突然間鈴聲大作, 隨即碰的一聲, 上方開了一個洞口。\n", me);

   if( killer= present("killer", environment( me)) )
   {
      tell_room(environment(me),HIW + "綠雲組上級殺手叫道:「擅闖者死...!!」\n" + NOR);
      if( me->query("combat_exp") < 15000)
      {
         message_vision("綠雲組上級殺手說道:「綠雲組不殺無名之徒, 你走吧...」\n", me);
         return 0;
      }
      killer->kill_ob( me);
   }
   set("exits/up", __DIR__"wood31.c");
   return 1;
}

int valid_leave(object me, string dir)
{
  if (dir != "up")
  {
     this_object()->delete("exits/up");
  }
  return 1;
}
