#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short","池底");
set ("long", @LONG
你運氣於單田，絕心要探個究竟，使出個千斤墜直往下沉，不一
會已潛至池底，突然水草中傳來一陣嬰兒啼聲，撥開水草一看，這下
子可是把你給嚇到了，原來這啼聲竟是來自一條全身金黃色的魚，你
默想這大概就是傳說中的娃娃魚了吧!!
LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/npc1/wawafish" : 1,
]));
  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 2 */
                "up": "/open/gsword/room/road1",
]));
  set("no_transmit", 1);
  setup();
}

void init()
{
add_action("do_search","search");
add_action("do_check","give");
}
int do_search(string str)
{
  object ob;
  ob=this_player();
message_vision("
你定睛一看，難道這就是傳說中的娃娃魚?? 魚的頭骨中有五個圓形孔洞，似乎可以放上什麼東西。\n",ob);
  return 1;
}

int do_check(string str)
{
 mapping weapon = ([
 "wawafish goldball" : 1,
 "wawafish fireball" : 2,
 "wawafish waterball" : 3,
 "wawafish woodball" : 4,
 "wawafish soilball" : 5,
 ]);
 object ob=this_player();
 object ob1;
 string name,str1,str2;
 if( !str || sscanf(str, "%s %s", str1, name) != 2 )
  {
    message_vision("請 give xxx xxx\n",ob);
  }
 else if(weapon[str] && ob->query("class")=="swordsman")
  {
   message_vision(HIW"你將法珠貫入娃娃餘頭骨中.頓時娃娃於大了一分\n"NOR,ob);
   if(weapon[str]==1) ob->set_temp("su1",1);
   if(weapon[str]==2) ob->set_temp("su2",1);
   if(weapon[str]==3) ob->set_temp("su3",1);
   if(weapon[str]==4) ob->set_temp("su4",1);
   if(weapon[str]==5) ob->set_temp("su5",1);

  }
 else
  {
   message_vision(HIW"你觸動機關-四周空氣隨之浮動,瞬間五行掛印浮出並發出一到耀眼的光芒!!!\n"NOR,ob);
   ob->unconcious();
   return 0;
  }
 if(ob->query_temp("su1")==1&&ob->query_temp("su2")==1&&ob->query_temp("su3")==1&&ob->query_temp("su4")==1&&ob->query_temp("su5")==1)
  {
   log_file("sword/yao",sprintf("%s(%s) free yao on %s\n",ob->query("name"),ob->query("id"),ctime(time()) ));
   tell_object(users(),HIC"逍遙子喜道 : 天憐仙劍..總算有人解開我長久以來的封印了...！！\n\n"NOR,ob);
   ob1 = present("wawafish",this_object());
   destruct(ob1);
   call_out("msg1",3,ob);
   return 1;
  }
}
int msg1(object ob)
{
   tell_object(users(),HIY"遙遠魔域傳來震天巨響！！！\n\n"NOR,ob);

   call_out("msg2",3,ob);
   return 1;
 }

int msg2(object ob)
{
   tell_object(users(),HIY"血魔狂笑道 : 仙劍老賊別得意，如今我封印將破！\n\n            看你還有本事在封我一次嗎??\n\n            哈~  哈~~  哈~~~  \n"NOR,ob);
   tell_object(users(),HIY"逍遙子嘆道 : 唉~~武道無寧日，從今起，凡我仙劍弟子全力對抗血魔一族 \n"NOR,ob);
   call_out("msg3",3,ob);
   return 1;
 }
int msg3(object ob)
{
  message_vision(HIY"看樣子你我真是有緣，你到仙劍後山劍聖峰來找我吧..我有其他事交代你。\n"NOR,ob);
  ob->set("quests/sunsword",1);
  ob->set("return",1);
  return 1;

}
