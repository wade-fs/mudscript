//增加十二天靈狩的判斷 補上 receive_damage() 的攻擊方參數 與增加死亡敘述 by blazakira 2011/11/18

#include <ansi.h>
#include <combat.h>
#include "/open/open.h" 
inherit NPC;
inherit SSERVER;

string magic1();
string magic2();
string magic3();
string magic4();
string magic5();
string sun4();
string sun5();

void create()
{
  set("class", "tendo");
  set_name("空間幻術師", ({ "space caster", "space", "caster" }) );
  set("title",HIW "穿梭古今"NOR);
  set("attitude", "peaceful");
  set("long","謎一般的幻術師，據說有通天遁地之能，擅長空間幻術..\n");
  set("gender","男性");
  set("combat_exp",24000000);
  set("score",9000000);
  set("sec_kee","god");
  set("max_s_kee",1000);
  set("s_kee",5000);
  set("age",410);
  set("class","bandit");
  set("max_gin",90000);
  set("max_kee",150000);
  set("max_sen",90000);
  set("bellicosity",99999);
  set("max_force",90000);
  set("force",999999);
  set("max_atman",50000);
  set("max_mana",50000);
  set("atman",60000);
  set("mana",60000);
  set("force_factor",70);
  set("no_mount",1);
  set("no_plan_follow",1);
  set("no_kill",1);
  set("no_fight",1);
  set_temp("roared",1);
  set("str",35);
  set("cor",35);
  set("cps",50);
  set("int",35);
  set("con",35);
  set("per",35);
  set("spi",35);
  set("kar",35);
  set("inquiry", ([
    "空間幻術":  (: sun4 :),
    "解決方法":  (: sun5 :),
  ]));
  set_skill("firestrike",140);
  set_skill("unarmed",150);
  set_skill("gold-magic",150);
  set_skill("ghost-steps",120);
  set_skill("badforce",240);
  set_skill("dodge",120);
  set_skill("parry",120);
  set_skill("force",500);
  map_skill("unarmed","firestrike");
  map_skill("magic", "gold-magic");
  map_skill("parry","firestrike");
  map_skill("force", "badforce");
  map_skill("dodge", "ghost-steps");
  set("chat_chance_combat",99);
  set("chat_msg_combat",({
    (: magic1 :),
    (: magic2 :),
    (: magic3 :),
    (: magic4 :),
    (: magic5 :),
  }) );
  set("mystery",1);
  set("ann_die",1);
  setup();
}

void heart_beat()
{
  object me,*target;
  int i,b,killair;
  me=this_object();
  if(!me || !environment(me)) return ;

  if(me->is_fighting() || me->is_killing())
  {
    if(living(me))
    {
      target=me->query_enemy();
      i=sizeof(target);

      if(random(7)==3)
      {
        message_vision(HIM"$N身形暴起，連環使出魔界金典上的滅世武學。\n\n"NOR,me);
        message_vision(HIW"
              ζ"HIC"天地神通"HIW"ζ"CYN"《"HIG"風變化"CYN"》
              \n"NOR,me);
        for(b=0;b<i;b++)
        {
          message_vision(HIW"狂風驟起，$N感覺到自己的身軀完全失去控制。\n"NOR,target[b]);
          target[b]->start_busy(1);
          COMBAT_D->report_status(target[b]);
        }
        message_vision(HIW"
              ζ"HIC"天地神通"HIW"ζ"CYN"《"HIY"雷變化"CYN"》
              \n"NOR,me);
        for(b=0;b<i;b++)
        {
          message_vision(HIW"巨雷劈下，$N被狂風捲住無法閃避，完全命中。\n"NOR,target[b]);
          target[b]->set("force",(target[b]->query("force"))*1/3);
          COMBAT_D->report_status(target[b]);
        }
        message_vision(HIW"
              ζ"HIC"天地神通"HIW"ζ"CYN"《"HIB"雨變化"CYN"》
              \n"NOR,me);
        for(b=0;b<i;b++)
        {
          message_vision(HIW"天地變異，$N目瞪口呆，任由隕石雨點般砸下。\n"NOR,target[b]);
          target[b]->receive_damage("kee",3000,me);
          COMBAT_D->report_status(target[b]);
        }
        message_vision(HIM"

            $N吼道：『無名小輩!!死吧!!』


"HIW"               ζ"HIY+BRED"魔典奧義"NOR""HIW"ζ"CYN"《"HIR"血穴神通"CYN"》
\n\n"NOR,me);
        for(b=0;b<i;b++)
        {   
          if(random(3) == 1)
          {
            message_vision(HIM"$N閃避不及，整個人撞進血穴之中，完全蒸發消失了。\n"NOR,target[b]);
            target[b]-> move ("/open/wiz/courthouse");
          } else {
            target[b]->receive_damage("gin",100,me);
            target[b]->receive_damage("sen",100,me);
            message_vision(YEL"$N及時由血穴謎陣中抽身，但身心已遭受重創。\n"NOR,target[b]);
          }
        }
      }
    }
  }
  me->clean_up_enemy();
  set_heart_beat(1);

  ::heart_beat();
}

string magic1()
{
  command("conjure magic-crazy");
  return "\n";
}

string magic2()
{
  command("conjure magic-wind");
  return "\n";
}

string magic3()
{
  command("conjure magic-thunder");
  return "\n";
}

string magic4()
{
  command("conjure magic-rain");
  return "\n";
}

string magic5()
{
  command("conjure magic-blood");
  return "\n";
}

string sun4()
{
  object me = this_player();
  int k;
  k = me->query_temp("ask-break-sun");
  if(!me) return"";
  if(me->query("family/family_name") != "射日派") return "什麼飯術!?";
  if(k>3) return "你願意幫我嗎?";
  if(me->query("break-sun")) return "我已送你去過了，人不能一直留戀過去，好自為之吧!!";
  if(!k || k<3) return "沒事問這做啥!?";
  if(this_object()->query_temp("cast-magic")) return "我不久前才送人去過，目前沒辦法再幫你了。";
  else {
    command("say 
沒錯，我的確會空間幻術，但是我年紀也大了，要施展一次空間幻術的靈力
也要消耗比較多，而且最近我的靈力總是不夠用，我知道只有一個解決方法
你如果幫我完成，我就為你施展空間幻術。");
    me->set_temp("ask-break-sun",4);
    this_object()->set_temp("cast-magic",1);
  }
  return "";
}

string sun5()
{
  object me = this_player();
  int k;
  k = me->query_temp("ask-break-sun");
  if(!me) return"";
  if(me->query("family/family_name") != "射日派") return "聽不懂啦!!";
  if(k>4) return "聚靈丹拿到了嗎?";
  if(me->query("break-sun")) return "我已送你去過了，人不能一直留戀過去，好自為之吧!!";
  if(!k || k<4) return "沒事問這做啥!?";
  else {
    command("say 
當今世上有一種奇藥，叫做聚靈丹，吃下之後能大幅提昇靈力，不過數量鮮
少，若你幫我取得，我就有足夠的靈力施展空間幻術了。");
    me->set_temp("ask-break-sun",5);
  }
  return "";
}

int accept_object(object me,object obj)
{
  int k;
  me = this_player();
  if(!me || !obj) return 1;
  k = me->query_temp("ask-break-sun");
  if(k && k==5 && obj->query("id")=="atman pill")
  {
    command("say 
好小子，你果然拿到了，很好！我已經在你體內種下時空種，只要在六芒星內發動
魔法陣(time-space go)就可以往來古今，但我的法力只能支撐三趟往返，好自為之
吧，請進。");
    me->set_temp("ask-break-sun",6);
    me->set_temp("break-sun/transmit",7);
  }
  else command("say 太好了!!");
  destruct(obj);
  return 1;
}

void die()
{
  object winner = query_temp("last_damage_from");
  int j;
  if(!winner)
  {
    ::die();
    return ;
  }
  if(winner == this_object())
  {
    ::die();
    return ;
  }
  command("想幹掉我，門兒都沒有，去死吧!!");
  winner->die();
  winner->move("/open/wiz/courthouse");
  :: die();
}
