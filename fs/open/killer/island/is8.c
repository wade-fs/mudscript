inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "沙灘");
  set ("long", @LONG
遍地的白沙, 除了一棵枯樹與一塊大岩之外, 並沒有其他事物. 你雖覺得枯
樹與岩石的感覺十分怪異, 但是經過仔細的尋找並沒有找到什麼奇怪的地方. 此
地除了東邊是海之外, 其他方向放眼望去都是白藹藹的沙灘, 在西北方能見到一
座高聳的岩壁.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"is7.c",
  "north" : __DIR__"is13.c",
  "south" : __DIR__"is5",
]));
  set("outdoors", "/u/u");

  setup();
}
void init()
{
add_action("do_closebox", "close");
add_action("do_search", "search");
add_action("do_look", "look");
add_action("do_get", "get");
add_action("do_put", "put");
}
int do_search()
{
object me=this_player();
if (me->query_temp("can_search")==1)
{
tell_object(me,HIC + "你赫然發現岩石的樹旁可以看到因退潮而呈現的沙岸上有一塊扁平的大岩石(stone).\n" + NOR);
tell_object(me,HIY + "原來黎明時是這座島退潮的時間 .\n" + NOR);
new(__DIR__"obj/stone.c")->move(environment(me));
me->delete_temp("can_search");
me->set_temp("can_back",1);
return 1;
}
else
{
return 0;
}
}
int do_look(string arg)
{
object me,ob;
me=this_player();
   if( !arg )
       return 0;
   if(arg!="box")
       return 0;
   if(me->query_temp("openbox")!=1)
       return 0;
else
{
tell_object(me,"裡面有:\n");
tell_object(me,HIW + "      一萬粒鑽石" + NOR + "(Diamond)\n" + NOR);
tell_object(me,HIB + "      忍術秘笈" + NOR + "(Ninja book)\n" + NOR);
return 1;
}
}
int do_get(string arg)
{
object me,ob;
me=this_player();
   if(me->query_temp("openbox")!=1)
       return 0;
   if( !arg )
       return 0;
   if(me->query_temp("can_close")==1)
       return 0;
   if(me->query_temp("care")==1)
{
tell_object(me,"你決定伸手拿取寶物,但是寶物一碰到你的手就變成煙霧消失了!!\n");
me->set_temp("care",2);
ob=present("box",this_object());
destruct(ob);
me->delete_temp("openbox");
return 1;
}
   if(arg=="all from box")
{tell_object(me,"你的良心呼籲你不要貪小便宜!!\n");me->set_temp("care",1);return 1;}
   if(arg!="daemond from box")
{tell_object(me,"你的良心呼籲你不要貪小便宜!!\n");me->set_temp("care",1);return 1;}
   if(arg!="book from box")
{tell_object(me,"你的良心呼籲你不要貪小便宜!!\n");me->set_temp("care",1);return 1;}
else
{
return 0;
}
}
int do_put(string arg)
{
object me,ob;
me=this_player();
   if( !arg )
       return 0;
   if(me->query_temp("openbox")!=1)
       return 0;
   if(arg!="card in box")
       return 0;
   if(me->query_temp("care")==2)
       return 0;
   if(me->query_temp("can_close")==1)
       return 0;
else
{
tell_object(me,"你將令牌放進金屬箱裡, 應該順手將盒子蓋\上(close)會比較好!!\n");
me->set_temp("can_close",1);
ob=present("card",me);
destruct(ob);
return 1;
}
}
int do_closebox(string arg)
{
object me,ob;
me=this_player();
   if( !arg )
       return 0;
   if(me->query_temp("openbox")!=1)
       return 0;
   if(arg!="box")
       return 0;
   if(me->query_temp("can_close")!=1)
       return 0;
else
{
tell_object(me,HIW + "你將盒子蓋\上!!\n");
tell_object(me,HIM + "突然間強烈的紫光從盒子射出!!\n");
tell_object(me,HIW + "強光過後只見盒子已經消失, 只留下一把生鏽的鐵匕首在地上!!\n");
new(__DIR__"obj/old_dag.c")->move(environment(me));
me->delete_temp("can_close");
ob=present("box",environment(me));
destruct(ob);
me->delete_temp("openbox");
if (me->query_temp("care")!=1) {me->set_temp("complete",1);return 1;}
return 1;
}
}

