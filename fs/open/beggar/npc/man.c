inherit NPC;
#include <ansi.h>
string name;
void create()
{
  set_name("傷心老人", ({ "sad man","man" }) );
  set("gender", "男性" );
  set("age",45);
  set("str",35);
  set("cor",45);
  set("cps",25);
  set("int",15);
  set("long","他是一個身穿破爛衣裳的乞丐.\n");
  set("combat_exp",350);
  set("attitude", "peaceful");
  set("chat_chance", 40);
  set("chat_msg", ({
      "老人說: 我好想念我兒呀～～\n",
       }) );
  set("inquiry",([
      "煉爐"   : "什麼煉爐？我只想要我的（兒）！\n",
      "兒"   : "我兒子多年前離家出走了，你幫我（找回）好不好？\n",
      "找回" : "他好像朝著日出方向走去，你去把整個狂想翻過一遍就可以了，等你消息了。",
      ]));
  set_skill("parry", 15);
  set_skill("dodge", 5);
  setup();
  add_money("coin", 25);
  carry_object("/obj/cloth")->wear();
}      

int accept_object(object me, object obj)
{
  me=this_player();
  if( obj->query("id") == "letter" 
      && me->query_temp("got_letter")==1
      && me->query("family/family_name")=="丐幫")
  {
   command("pat "+getuid(me));
   command("say 嗚．．我兒呀～可終於讓爹等到你的消息了。");
   command("say 小兄弟太感謝你了，我就幫你煉杖來做為回報吧。");
   command("say 你先跟我去一個聖地。\n");
   me->move("/open/beggar/room/staffroom");
   name=me->query("id",1);
   call_out("do_staff",2);
  }
  else
  {
   command("say 我要我兒～～我要我兒～～");
  }
   destruct(obj);
   return 1;
}
void do_staff1()
{
  object me=this_player();
  message_vision(HIY"老人緩緩唸起了經文～～\n"NOR,me);
  message_vision("\n\t"HIW"羯諦羯諦。\n"NOR,me);
  call_out("do_staff2",2);
}
void do_staff2()
{
  object me=this_player();
  message_vision("\n\t"HIM"波羅羯諦。\n"NOR,me);
  call_out("do_staff3",2);
}
void do_staff3()
{
  object me=this_player();
  message_vision("\n\t"HIW"波羅僧羯諦。\n"NOR,me);
  call_out("do_staff4",2);
}
void do_staff4()
{
  object me=this_player();
  message_vision("\n\t"HIM"菩提薩婆訶。\n"NOR,me);
  call_out("do_staff5",2);
}
void do_staff5()
{
  object me=this_player();
  message_vision("\n"HIR"剎時煉爐嗡嗡作響．．．此時．．．．\n"NOR,me);
  message_vision(HIR"從爐中緩緩升起一把杖身清澈可透光的奇杖。\n"NOR,me);
  tell_object(users(),HIC"
                \t難定紛紛甲子年\n\n"NOR);
  call_out("do_staff6",2);
}
void do_staff6()
{
  tell_object(users(),HIC"
                \t    千魔蕩蕩白陽天\n\n"NOR);
  call_out("do_staff7",2);
}
void do_staff7()
{
  tell_object(users(),HIC"
                \t        蒼天旨意著書命\n\n"NOR);
  call_out("do_staff8",2);
}
void do_staff8()
{
  tell_object(users(),HIC"
                \t            諸子虔誠扶道顛\n\n"NOR);
  call_out("do_staff9",2);
}
void do_staff9()
{
  tell_object(users(),HIC"
                \t                殘燈點亮華光現\n\n"NOR);
  call_out("do_staff10",2);
}
void do_staff10()
{
  tell_object(users(),HIC"
                \t                    一線生機救末年\n\n"NOR);
  call_out("do_staff11",2);
}
void do_staff11()
{
  object me=this_player();
   tell_object(users(),HIW"
                "+me->query("name")+"笑道！哈～哈～我出運了！

                費經心力，終於拿到"HIC"稀世珍寶了"HIW"！
                    
                     以後我將以此來俠義武林！\n\n"NOR);
}
void do_staff()
{
   object me=this_player();
   message_vision(HIG"$N跟著老人來到聖地，一股神聖之氣油然而生。\n"NOR,me);
   this_object()->move("/open/beggar/room/staffroom");
   command("say 小兄弟，你把收集到的惡人依序放入各爐內吧！\n");
   command("say 詳細方法請看 VCR！\n");
   command("say 開始吧！\n");
   me->set_temp("can_put",1);
}
