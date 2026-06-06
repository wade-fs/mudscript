//調整殺手墓園的判斷 並補上接受東西時的回應 by blazakira 2011/8/5

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void call_find_ljen(object user,object ghost)
{
  command("say 都聽到了吧，快去把那混帳東西的豬頭帶回來，讓我好好為她超渡一下。");
  command("say 別忘了再去土地公處買些香火和紙錢回來ㄚ。");
  user->set_temp("ghost", 2);
}

void create()
{
  object ob;
  set_name("周八伯",({"eight uncle","eight","uncle"}) );
  set("long","此人不僅一身功\夫了得，而且精通歧黃之術，是一位相當可怕的敵人\n");
  set("race", "人類");
  set("gender","男性");
  set("combat_exp", 700000);
  set("age",55);
  set("title","綠雲組組長");
  set("class","killer");
  set("cor",99);
  set("cps",99);
  set("str",45);
  set("kee",3300);
  set("max_kee",3300);
  set("force",3000);
  set("max_force",3000);
  set("force_factor", 10);
  set("bellicosity",1700);
  set_skill("rain-throwing",100);
  set_skill("throwing",120);
  set_skill("blackforce",85);
  set_skill("force",90);
  set_skill("shade-steps",100);
  set_skill("dodge",100);
  set_skill("parry",90);
  map_skill("dodge","shade-steps");
  map_skill("move", "shade-steps");
  map_skill("force","blackforce");
  map_skill("throwing","rain-throwing");
  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
    (:perform_action,"throwing.manakee":),
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
  if( me->query("id") == "ljen")//將任盈盈帶來
    call_out("greeting",1,me);
}

int accept_object( object me, object obj)
{
  string obj_name= obj->query("name");

  if( me->query_temp("ghost") != 3) //還沒殺死陳星輝的話就不處理
    return 1;

  if( obj_name == "陳星輝的頭")
  {
    command("say hmm...這果然是陳星輝的頭。");
    me->set_temp("shead", 1);
  }
  else if( obj_name == "香火")
  {
    command("say hmm...這果然是香火。");
    me->set_temp("incense", 1);
  }
  else if( obj_name == "金紙")
  {
    command("say hmm...這果然是金紙。");
    me->set_temp("gpaper", 1);
  }
  if( me->query_temp("shead") && me->query_temp("incense") && me->query_temp("gpaper")) //取消else 讓達成任務就直接完成
  {
    command("say 東西都到齊了，那就讓我開始為任盈盈超渡吧...");
    message_vision("只見周八伯又拿起他的鈴鐺，燃香點燭，口中念念有詞...\n", me);
    message_vision("隨即大喝一聲，只聽見任盈盈的聲音在遠處響起～\n\n", me);
    message_vision(HIB"\t謝謝$N的大恩大德，小女子無以為報。\n"NOR, me);
    message_vision(HIB"\t小女子在生前曾得到一些相當特別的藥丸，\n"NOR,me);
    message_vision(HIB"\t為了避免被別人發現，所以就將它藏在$N的棺木內，\n"NOR, me);
    message_vision(HIB"\t小女子就以這些丹藥當成對$N的報答好了........\n\n"NOR, me);
    command("say 既然她已經走了，你也該離開了。");
    me->set_temp("ghost", 4);
  }
  else
    command("say 給我這個做什麼。");
  destruct(obj);
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
    message_vision(HIB"\n綠雲組一級殺手看到組長有難，馬上向$N攻過來！\n"NOR,me);
    guard->kill_ob(me);
    return 1;
  }
}
/*
void greeting(object ghost)
{
  object me= ghost->query_leader();
  if(!me) { command("say ?!"); }
  else if( me->query_temp("ghost") == 1)  //只要能把鬼帶來的人都會等於 1
  {
    command("say "+(me->query("gender")=="男性" ? "壯士" : "姑娘")+"看你印堂發黑，似乎是被鬼上身了。");
    command("hmm");
    command("say 讓我即刻升堂作法，看看附身在你身上的鬼有什麼話說。");
    message_vision("只見周八伯拿起鈴鐺，燃香點燭，口中念念有詞...\n", me);
    message_vision("旋即一陣白煙從你頭上冒出化身成人形......\n\n", me);
    ghost->delete_temp("invis");
    ghost->do_command("say 小女子生前是一名殺手，到墓園逛逛時被某人由背後偷襲...");
    ghost->do_command("say 後來那個豬狗不如的東西竟然.....");
    ghost->do_command("cry "+ me->getuid());
    ghost->do_command("say 請"+(me->query("gender")=="男性" ? "壯士" : "姑娘")+"替小女子報仇，據小女子所知，那人正在黑風組總部作客。");
    ghost->do_command("say 如能替小女子報得大仇，小女子願以身相許\...。");
    message_vision(HIW"任盈盈講完這些話時，又化成一陣煙消失了。\n\n"NOR, me);
    command("say 都聽到了吧，快去把那混帳東西的豬頭帶回來，讓我好好為她超渡一下。");
    command("say 別忘了再去土地公處買些香火和紙錢回來ㄚ。");
    me->set_temp("ghost", 2);
    destruct(ghost);
  }
}
*/
void greeting(object obj)
{
  object me= obj->query_leader();
  if(!me) { command("say ?!"); }
  else if( me->query_temp("ghost") == 1) //只要能把鬼帶來的人都會等於 1
  {
    command("say "+(me->query("gender")=="男性" ? "壯士" : "姑娘")+"看你印堂發黑，似乎是被鬼上身了。");
    command("hmm");
    command("say 讓我即刻升堂作法，看看附身在你身上的鬼有什麼話說。");
    message_vision("只見周八伯拿起鈴鐺，燃香點燭，口中念念有詞...\n", me);
    message_vision("旋即一陣白煙從你頭上冒出化身成人形......\n\n", me);
    foreach(object mob in all_inventory(environment()))
    {
      if(mob->query("id")=="ljen")
      {
        mob->call_find_eight(me,this_object());
      }
    }
  }
}
