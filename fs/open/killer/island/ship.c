inherit ROOM;
#include <ansi.h>
string out();
void create ()
{
  set ("short", "商船中");
  set ("long", @LONG
房間的擺設十分的簡單，除了幾張固定的雙層木床外，幾乎
可以說空無一物了，在每一張木床旁，都有一個可以向外眺望的
圓形玻璃窗，你可以透過窗戶看看外面(out)的景象。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "out" : (: out :),
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shipm.c" : 3,
  __DIR__"npc/son.c" : 1,
]));
  set("light_up", 1);

  setup();
}

string out()
{
 object ob;
 object me;
 ob=this_object();
 me=this_player();
 if (me->query_temp("lookout") != 1)
 {
 tell_object(me,HIY"你往遠處望去 ,只見商船緩緩航行在海上 ,海上天氣晴朗 ,風平浪淨 ,讓你感到十分舒服."NOR);
 me->set_temp("lookout",1);
 call_out("out_01",10,me);
 return "\n";
 }
 else return "沒看到啥特別的東西\n";
}
int out_01(object me)
{
tell_object(me,HIR"\n海面上天氣突然轉陰 ,並且刮起大風!!\n"NOR);
call_out("out_02",2,me);
return 1;
}
int out_02(object me)
{
tell_object(me,HIR"\n海面上的浪越來越大 ,風也越刮越強!!\n"NOR);
call_out("out_03",2,me);
return 1;
}
int out_03(object me)
{
tell_object(me,HIY"\n甲板上的船員回報 :風浪太強 ,船隻已經失控偏離航向了!!\n"NOR);
call_out("out_04",2,me);
return 1;
}
int out_04(object me)
{
tell_object(me,HIY"\n嗯....希望這惡劣的天氣能趕快過去....\n"NOR);
call_out("out_05",2,me);
return 1;
}
int out_05(object me)
{
tell_object(me,HIW"\n船隻在海面上劇烈的搖晃著 ,船員都開始有了暈船的現象....\n"NOR);
call_out("out_06",2,me);
return 1;
}
int out_06(object me)
{
tell_object(me,HIR"\n突然轟隆一聲 ,船隻似乎撞上了什麼東西 .\n"NOR);
call_out("out_07",2,me);
return 1;
}
int out_07(object me)
{
tell_object(me,HIY"\n一位船員回報 :我們現在擱淺在一座小島上 ,船底破了一個大洞 ,我們得趕快先將物品運出船外!!\n"NOR);
call_out("out_08",1,me);
return 1;
}
int out_08(object me)
{
me->move("/open/killer/island/is4.c"); 
return 1;
}

