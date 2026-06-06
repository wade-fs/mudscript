// 網聚獎品替身發放房間!!!
#include <room.h>
#include <ansi.h>
inherit ROOM;
string *user_gift_2 = ({
"palla","trust","luner","gendor","chritina","yukigirl"})
,*user_gift_3 = ({"leing","aspire","zero","amy","pnx"})
,*user_gift_5 = ({"lancelin","dunga","chan"})
,*user_max_force=({"guility","apple","sillyboy","mudcom","nicklin","cyberfight","aro",
"windows","pzp","copy","ansys","shian","women","roman","aait","namie","leing","chan"});
void create ()
{
set ("short",HIY + "網聚獎品『屬性、技能、內力最大值』發放處" + NOR);
set ("long","這次網聚共有將近七十位玩家參加!!!!
網聚的獎品單請打help fs_net及help fs_net2
此房間是用來發放網聚獎品的房間!!
東邊的房間是發放替身的房間!!!
說明如下：
屬性的部份：
           1.請先打check_gift 主要是確認你是不是可以加屬性
           2.在打get_gift <屬性的英文> <數值> 主要是加某屬性數值
             ex: get_gift con 3
固定的屬性的部份：
           1.請打get_fix_gift
固定的技能的部份：
           1.請打get_basic_force 加基本心法
           2.請source及wasain請post你要加的特別內\功心法,才能加入程式!!!!
內力最大值的部份：
           1.請打get_max_force

");
  set("no_kill",1);
  set("no_fight",1);
  set("light_up",1);
  set("exits", ([
  "east" : "/open/wiz/stbyroom",
]));
  setup();
}

void init()
{
add_action("in_fix_gift","get_fix_gift");
add_action("in_max_force","get_max_force");
add_action("in_basic_force","get_basic_force");
add_action("in_check","check_gift");
add_action("in_gift","get_gift");
}
int in_fix_gift()
{
 object me = this_player();
 string name=me->query("id");
 if(!me->query("fs_net3/fix_gift"))
  {
   if(name == "fee")
    {
     write("恭喜你得到了全滿的臂力及外表屬性!!!\n");
     me->set("str",35);
     me->set("per",35);
     me->set("fs_net3/fix_gift",1);
     log_file("net/gift", sprintf("%s(%s) 領取網聚獎品!!屬性臂力、外表全滿!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
   }else if(name == "catbaby")
   {
     write("恭喜你得到了全滿的臂力及外表屬性!!!\n");
     me->set("str",35);
     me->set("per",35);
     me->set("fs_net3/fix_gift",1);
     log_file("net/gift", sprintf("%s(%s) 領取網聚獎品!!屬性臂力、外表全滿!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
 }else if(name=="evilshadow")
   {
     write("恭喜你得到了全滿的外表屬性!!!\n");
     me->set("per",35);
     me->set("fs_net3/fix_gift",1);
     log_file("net/gift", sprintf("%s(%s) 領取網聚獎品!!屬性外表全滿!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
   }else if(name=="libra")
   {
     write("恭喜你得到了全滿的臂力屬性!!!\n");
     me->set("str",35);
     me->set("fs_net3/fix_gift",1);
     log_file("net/gift", sprintf("%s(%s) 領取網聚獎品!!屬性臂力、外表全滿!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
   }else
   write("你沒有固定屬性可以領!!!\n");
   return 1;
  }
  write("你以經領了!!!\n");
  return 1;
}
int in_basic_force()
{
 object me = this_player();
 string name=me->query("id");
 int skill_value;
 if(!me->query("fs_net3/basic_force"))
  {
   if(name == "success")
    {
     write("恭喜你得到了一百點的基本內\功心法!!!\n");
     skill_value=me->query_skill("force",1);
     skill_value=skill_value+100;
     me->set_skill("force",skill_value);
     me->set("fs_net3/basic_force",1);
     log_file("net/gift", sprintf("%s(%s) 領取網聚獎品!!基本內力心法加五十級!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
   }else if(name == "wasain")
   {
     write("恭喜你得到了五十點的基本內\功心法!!!\n");
     skill_value=me->query_skill("force",1);
     skill_value=skill_value+50;
     me->set_skill("force",skill_value);
     me->set("fs_net3/basic_force",1);
     log_file("net/gift", sprintf("%s(%s) 領取網聚獎品!!基本內力心法加五十級!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
   }else
   write("你沒有在名單之上!!\n");
   return 1;
  }
  write("你以經領了!!!\n");
  return 1;
}
int in_max_force()
{
object me = this_player();
string name=me->query("id");
int i,j,number=sizeof(user_max_force);
if(!me->query("fs_net3/max_force"))
 {
   if(name=="aait") {
write("恭嘉你內力值加二百點!!!\n");
me->add("max_force",200);
me->set("fs_net3/max_force",1);
log_file("net/max_force",sprintf("%s(%s)領取網聚獎品!!內力最大值加二百點!!時間是%s!!\n",me->query("name"),me->query("id"),ctime(time()) ));
return 1;
}else
   for (j=0; j<number; j++)
    if(user_max_force[j] == name)
     {
     write("恭喜你內力值加一百點!!!\n");
     me->add("max_force",100);
     me->set("fs_net3/max_force",1);
     log_file("net/max_force", sprintf("%s(%s) 領取網聚獎品!!內力最大值加一百!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
     }
    write("sorry!!你並不在名單上!!!\n");
    return 1;
 }
    write("你以經領了!!!\n");
    return 1;
}
int in_check()
{
object me = this_player();
string name=me->query("id");
int i,j,number=sizeof(user_gift_2);
if(!me->query("fs_net3/check_gift"))
 {
   for (j=0; j<number; j++)
    if(user_gift_2[j] == name)
     {
     me->set("fs_net3/check_gift",1);
     me->set("fs_net3/gift_number",2);
     write("恭喜你通過CHECK你有二點的屬性增加值 !!!\n");
     log_file("net/check_gift", sprintf("%s(%s) 通過屬性Check!!可以得到二點屬性!!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
     }
    number=sizeof(user_gift_3);
   for (j=0; j<number; j++)
    if(user_gift_3[j] == name)
     {
     me->set("fs_net3/check_gift",1);
     me->set("fs_net3/gift_number",3);
     write("恭喜你通過CHECK你有三點的屬性增加值 !!!\n");
     log_file("net/check_gift", sprintf("%s(%s) 通過屬性Check!!可以得到三點屬性!!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
     }
    number=sizeof(user_gift_5);
   for (j=0; j<number; j++)
    if(user_gift_5[j] == name)
     {
     me->set("fs_net3/check_gift",1);
     me->set("fs_net3/gift_number",5);
     write("恭喜你通過CHECK你有五點的屬性增加值 !!!\n");
     log_file("net/check_gift", sprintf("%s(%s) 通過屬性Check!!可以得到五點屬性!!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
     }
    write("sorry!!你並不在名單上所以沒有任何屬性可以增加!!!\n");
    return 1;
  }
    write("你以經通過CHECK了!!!若想知道你有多少屬性可以加請打help fs_net3\n");
    return 1;
}
int in_gift(string arg)
{
  object me = this_player();
  string name=me->query("id"),gift;
  int number;
  if( !arg ) {
     write("格式錯誤!!!!\n");
     return 1;
  }
  if( sscanf(arg,"%s %d",gift,number) != 2 ) {
     write("格式錯誤!!!!\n");
     return 1;
  }
  if(!me-query("fs_net3/check_gift")){
     write("你尚未經過CHECK!!!!!\n");
     return 1;
  }
  if(me->query("fs_net3/gift_number") < 1) {
     write("你的屬性點數用完了!!\n");
     return 1;
  }
  if(me->query("fs_net3/gift_number") < number) {
     write("你的屬性點數不夠哦!!\n");
     return 1;
  }
  if((gift != "con")&&(gift != "str")&&(gift != "kar")&&(gift != "int")&&(gift != "cps")&&
(gift != "spi") && (gift != "per") && (gift != "cor")) {
     write("沒有這種屬性!!!!\n");
     return 1;
  }
  me->add(gift,number);
  me->add("fs_net3/gift_number",-number);
  write("屬性增加增加成\功!!\n");
 log_file("net/gift", sprintf("%s(%s) 通過加屬性%s，加了%d!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),gift,number,ctime(time()) ));
     return 1;
}
