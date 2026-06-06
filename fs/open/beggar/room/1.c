#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIC + "茅廬" + NOR);
  set ("long", @LONG

這是一間破舊的茅廬，然而屋裡四處放著各式打鐵工具，
屋子正中，一座爐子正燃燒著熊熊烈火，幾塊熟鐵和不知
名的奇異金屬則躺在爐子裡，看來像是將要打造一把特殊
的兵器。爐壁上似乎刻著不甚清楚的小字...
LONG);
  set("item_desc", ([ /* sizeof() == 2 */
      "煉爐" : "用來提煉神兵利器用的，似乎需要些引子放入其中。\n",
      "爐壁"  :"
刑命屬金  梁命屬木  

    疆命屬水  方命屬火

        李命屬土  鬥者無心  
                          
                       黃生非人\n",
]));

  set("exits", ([ /* sizeof() == 3 */
      ]));
  set("objects",([
      "/open/beggar/obj/furnace" : 1,
        ]));
  set("no_auc", 1);
  set("no_transmit", 1);
  setup();
}
void init()
{
  add_action("do_put","put");
}

int do_put(string str)
{
  mapping heads = ([
  "lan-head in 木" : 1,
  "liung-head in 土" : 2,
  "lee-head in 水" : 3,
  "chung-head in 火" : 4,
  "pin-head in 金" : 5,
  "cow-head in 心" : 6,
  "hung-head in 人" : 7,
                   ]);
  object ob=this_player();
  string name,str1,str2;
  object superstaff;
  if(ob->query("beggar/got_cloudstaff")==1)
    return notify_fail("你解完打狗棒謎了！！\n");
  if(ob->query_temp("can_put") != 1)
    return notify_fail("你沒有得到老生先的允許\！\n");
  if( !str || sscanf(str, "%s in %s", str1, name) != 2 )
  {
   message_vision("請 put xxx in xxx\n",ob);
  }
  else if(heads[str])
  {
   message_vision(HIW + "你把人頭置於穴位，一道靈氣飛入煉爐內！\n" + NOR,ob);
   if(heads[str]==1) ob->set_temp("aa1",1);
   if(heads[str]==2) ob->set_temp("aa2",1);
   if(heads[str]==3) ob->set_temp("aa3",1);
   if(heads[str]==4) ob->set_temp("aa4",1);
   if(heads[str]==5) ob->set_temp("aa5",1);
   if(heads[str]==6) ob->set_temp("aa6",1);
   if(heads[str]==7) ob->set_temp("aa7",1);
  }
  else
  {
   message_vision(HIR + "你一時心急錯放五行位置。\n" + NOR,ob);
   ob->unconcious();
  }
  if(ob->query_temp("aa1")==1&&ob->query_temp("aa2")==1&&ob->query_temp("aa3")==1
     &&ob->query_temp("aa4")==1&&ob->query_temp("aa5")==1&&ob->query_temp("aa6")==1
     &&ob->query_temp("aa7")==1)
  {
   message_vision(HIW + "頓時中間的墳墓～～～嘎嘎作響。\n" + NOR,ob);
   destruct(present("pin-head",ob));
   destruct(present("liung-head",ob));
   destruct(present("lee-head",ob));
   destruct(present("lan-head",ob));
   destruct(present("hung-head",ob));
   destruct(present("cow-head",ob));
   destruct(present("chung-head",ob));
   call_out("do_staff1",2);
   superstaff=new("/open/beggar/obj/poor_staff.c");
   superstaff->move(ob);
   ob->set_temp("got_poor_staff",1);
  }
  return 1;
}
void do_staff1()
{
  object me=this_player();
  message_vision(HIR + "老人緩緩唸起了經文～～\n" + NOR,me);
  message_vision("\n\t" + HIW + "羯諦羯諦。\n" + NOR,me);
  call_out("do_staff2",2);
}
void do_staff2()
{
  object me=this_player();
  message_vision("\n\t" + HIM + "波羅羯諦。\n" + NOR,me);
  call_out("do_staff3",2);
}
void do_staff3()
{
  object me=this_player();
  message_vision("\n\t" + HIW + "波羅僧羯諦。\n" + NOR,me);
  call_out("do_staff4",2);
}
void do_staff4()
{
  object me=this_player();
  message_vision("\n\t" + HIM + "菩提薩婆訶。\n" + NOR,me);
  call_out("do_staff5",2);
}
void do_staff5()
{
  object me=this_player();
  message_vision(HIY + "\n剎時煉爐嗡嗡作響．．．此時．．．．\n" + NOR,me);
  message_vision(HIY + "從爐中緩緩升起一把杖身清澈可透光的奇杖。\n" + NOR,me);
  tell_object(users(),HIC + "
                \t難定紛紛甲子年\n\n" + NOR);
  call_out("do_staff6",2);
}
void do_staff6()
{
  object me=this_player();
  tell_object(users(),HIC + "
                \t    千魔蕩蕩白陽天\n\n" + NOR);
  call_out("do_staff7",2);
}
void do_staff7()
{
  object me=this_player();
  tell_object(users(),HIC + "
                \t        蒼天旨意著書命\n\n" + NOR);
  call_out("do_staff8",2);
}
void do_staff8()
{
  object me=this_player();
  tell_object(users(),HIC + "
                \t            諸子虔誠扶道顛\n\n" + NOR);
  call_out("do_staff9",2);
}
void do_staff9()
{
  object me=this_player();
  tell_object(users(),HIC + "
                \t                殘燈點亮華光現\n\n" + NOR);
  call_out("do_staff10",2);
}
void do_staff10()
{
  object me=this_player();
  tell_object(users(),HIC + "
                \t                    一線生機救末年\n\n" + NOR);
  call_out("do_staff11",2);
}

void do_staff11()
{
  object me=this_player();
  tell_object(users(),HIW + "
                "+me->query("name")+"笑道！哈～哈～我出運了！

                費經心力，終於拿到" + HIC + "稀世珍寶了" + HIW + "！
                    
                     以後我將以此來俠義武林！\n\n" + NOR);
}

