#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
   object ob;
   set_name("周八伯",({"eight uncle","eight","uncle"}) );
   set("long","此人不僅一身功\夫了得, 而且精通歧黃之術, 是一位相當可怕的敵人\n");
   set("race", "人類");
   set("gender","男性");
   set("combat_exp", 600000);
   set("age",50);
   set("title","綠雲組組長");
   set("class","killer");
   set("cor",30);
   set("cps",30);
   set("str",30);
   set("kee",2300);
   set("max_kee",2300);
   set("force",1500);
   set("max_force",1500);
   set("force_factor", 10);
   set("bellicosity",900);
   set_skill("rain-throwing",80);
   set_skill("throwing",85);
   set_skill("blackforce",75);
   set_skill("force",85);
   set_skill("shade-steps",90);
   set_skill("dodge",90);
   set_skill("parry",85);
   map_skill("dodge","shade-steps");
   map_skill("move", "shade-steps");
   map_skill("force","blackforce");
   map_skill("throwing","rain-throwing");

   set("chat_chance_combat", 20);
   set("chat_msg_combat", ({
           (:perform_action,"throwing.rain":),
   }));

   setup();
   add_money("gold", 10);
   ob=carry_object("/open/killer/obj/lustar");
   ob->add_amount(500);
   ob->wield();
   carry_object("/open/killer/weapon/k_cloth2.c")->wear();
}

void init()
{
   object me= this_player();
   ::init();
   if( me->query("id") == "ljen")
      call_out("greeting",1,me);
}

int accept_object( object me, object obj)
{
   string obj_name= obj->query("name");

   if( me->query_temp("ghost") != 3)            //還沒殺死陳星輝的話就不處理
      return 1;

   if( obj_name == "陳星輝的頭")
   {
      command("say hmm...這果然是陳星輝的頭");
      me->set_temp("shead", 1);
   }
   else if( obj_name == "香火")
      me->set_temp("incense", 1);
   else if( obj_name == "金紙")
      me->set_temp("gpaper", 1);
   else if( me->query_temp("shead") && me->query_temp("incense") && me->query_temp("gpaper"))
   {
      command("say 東西都到齊了, 那就讓我為開始為任盈盈超渡吧...");
      message_vision("只見周八伯又拿起他的鈴鐺, 燃香點燭, 口中念念有詞...\n", me);
      message_vision("隨即大喝一聲, 只聽見任盈盈的聲音在遠處響起\n", me);
      message_vision(HIB + "謝謝$N的大恩大德, 小女子無以為報, 不過小女子在生前曾得到一些相當特別\n" + NOR, me);
      message_vision(HIB + "的藥丸, 為了避免被別人發現, 所以就將它藏在你的棺木內, 小女子就以這些\n" + NOR, me);
      message_vision(HIB + "丹藥當成對你的報答好了........" + NOR, me);
      me->set_temp("ghost", 4);
   }
   else
      command("say 給我這個做什麼。");
   return 1;
}
int accept_fight(object me)
{
   return 1;
}
int accept_kill( object me)
{
   object guard;

   add("bellicosity",700);
   command("cmd bellup");

   guard=present( "killer 2",environment(me) );
   if( !present( "killer 2",environment(me))||!living(guard))
      return 1;
   else
   {
      tell_room(environment(me),"一起上！有人找碴!給我拿下 \n"),
      message_vision(HIB + "\n綠雲組一級殺手看到組長有難，馬上向$N攻過來！\n" + NOR,me);
      guard->kill_ob(me);
      return 1;
   }
}
void greeting(object ghost)
{
   object me= ghost->query_leader();
   if( me->query_temp("ghost") == 1)  //只要能把鬼帶來的人都會等於 1
   {
      command("say "+(me->query("gender")=="男性" ? "壯士" : "姑娘")+"看你印堂發黑, 似乎是被鬼上身了。");
      command("hmm");
      command("say 讓我即刻升堂作法, 看看附身在你身上的鬼有什麼話說。");
      message_vision("只見周八伯拿起鈴鐺, 燃香點燭, 口中念念有詞...\n", me);
      message_vision("旋即一陣白煙從你頭上冒出化身成人形......\n", me);
      ghost->delete_temp("invis");
      ghost->command("say 小女子生前是一名殺手, 某天到墓園逛逛時卻被某人由背後偷襲...後來那個豬狗不如的東西竟然.....");
      ghost->command("cry "+ me->getuid());
      ghost->command("say 請"+(me->query("gender")=="男性" ? "壯士" : "姑娘")+"替小女子報仇, 據小女子所知, 那人正在黑風組總部作客。");
      ghost->command("say 如能替小女子報得大仇, 小女子願以身相許\...。");
      message_vision(HIW + "任盈盈講完這些話時, 又化成一陣煙消失了。" + NOR, me);
      command("say 都聽到了吧, 快去把那混帳東西的豬頭帶回來, 讓我好好為她超渡一下, 別忘了再去土地公處買些香火 紙錢回來ㄚ。");
      me->set_temp("ghost", 2);
      destruct( ghost);
   }
}
