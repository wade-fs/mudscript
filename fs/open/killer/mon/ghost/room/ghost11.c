//written by acelan...../u/a/acelan/ghost/room/ghost11.c
inherit ROOM;
void create()
{
object me=this_player();
        set("short", me->query("name")+"的墓穴");
        set("long", @LONG
這裡面陰森森的, 四面空盪盪的, 沒有任何東西, 只有前方擺著
一口棺木(coffin), 看起來還挺新的, 不知道裡面睡的是什麼人, 竟
然敢搶走我的床位。
LONG);
   set("exits", ([ /* sizeof() == 1 */
       "east"  : __DIR__"ghost12.c",
   ]));
   set("item_desc", ([ /* sizeof() == 1 */
       "coffin" : "這是一口棺木\n",
   ]));
   setup();
}

void init()
{
object me=this_player();
        set("short", me->query("name")+"的墓穴");
        set("long", @LONG
這裡面陰森森的, 四面空盪盪的, 沒有任何東西, 只有前方擺著
一口棺木(coffin), 看起來還挺新的, 不知道裡面睡的是什麼人, 竟
然敢搶走我的床位。
LONG);
   add_action("do_open", "open");
   add_action("do_search", "search");
}

int do_search( string arg)
{
object me=this_player();
   if( arg != "coffin")
   {
      message_vision("你找來找去, 什麼也沒發現...\n", me);
      return 0;
   }
   if( me->query_temp("ghost", 1) < 3)
   {
      message_vision("你仔細地將你的棺木四周都找了一遍, 可是卻沒有什麼發現。\n", me);
      return 0;
   }
   message_vision("你將你的棺木仔細的搜索一遍, 發現它還未封棺, 應該是可以打開(open)的。\n", me);
   me->set_temp("ghost", 4);
   return 1;
}

int do_open( string arg)
{
object me=this_player();
   object ob;
   if( arg != "coffin")
   {
      message_vision("你要打開什麼.........\n", me);
      return 0;
   }
   if( me->query_temp("ghost", 1) < 4)
   {
      message_vision("你大喝一聲, 使出你吃奶的力氣, 可是棺木就是聞風不動。\n", me);
      return 0;
   }
   message_vision("你使勁的將你的棺木打開後, 赫然發現裡面堆滿了各式各樣的寶物。\n", me);
   message_vision("想想那是自己的陪葬品，也不好意思多拿，只取走了那一個丹藥。\n", me);
   if (me->query("quest/worldpill") < 1)
   {//避免有其他玩家幫忙拿pill
	   ob = new( "/open/killer/mon/ghost/obj/worldpill" );
	   ob->move(me);
	   me->set_temp("getpill",1);  //代表親自拿，才有資格吃（相關設定在worldpill）
   }
   me->delete_temp("ghost"); //避免連續拿取
   return 1;
}


