// fire phoenix---made by nike
//由於獎勵豐富 因此增加內力的參數來增加難度 雖然基本上是不用打這隻啦XD by blazakira 2011/3/20

#include <ansi.h>
inherit NPC;

mapping *action = ({
  ([
    "action" :  "$N"HIR"鼓動起一雙巨大的翅膀，振翅向$n撲去，其所挾帶的狂風，拍打得$n是頭暈又目眩！"NOR,
    "dodge"    :  -35,
    "parry"    :  -40,
    "damage"   :  350,
    "damage_type":  "拍傷",
  ]),
  ([
    "action" :  "$N"HIR"舞起兩隻有力的爪子，狠狠的朝$n抓去，$n閃避不及，背上留下了六條明顯的血痕！"NOR,
    "dodge"    :  -35,
    "parry"    :  -40,
    "damage"   :  370,
    "damage_type":  "抓傷",
  ]),
  ([
    "action" :  "$N"HIR"突然昂首一鳴，聲畢，便挺起尖喙往$n的身上猛啄，$n無法躲避，被啄的哀嚎大起！"NOR,
    "dodge"    :  -35,
    "parry"    :  -40,
    "damage"   :  400,
    "damage_type":  "啄傷",
  ]),
  ([  "action" :  "$N"HIR"抖動全身之羽毛，並試著以自己灼熱的身體衝撞$n，使得$n的身體受到了嚴重的灼傷！"NOR,
    "dodge"    :  -35,
    "parry"    :  -40,
    "damage"   :  430,
    "damage_type":  "灼傷",
  ]),
  ([
    "action" :  "$N"HIR"猛的跳起，用尾巴使勁甩向$n的頭部，$n一時閃神，被打了個正著，使得面頰發腫！"NOR,
    "dodge"    :  -35,
    "parry"    :  -40,
    "damage"   :  450,
    "damage_type":  "打傷",
  ]),
});

void create()
{
  set_name(HIR"赤羽火鳳"NOR, ({"fire phoenix","phoenix","pnx"}) );
  set("race", "野獸");
  set("title",HIY"瀧山鎮派聖獸"NOR);
  set("long", "一隻羽毛非常美麗的火鳳凰，是瀧山派的鎮派聖獸，你可以嘗試拔(pluck)牠的羽毛(feather)！\n");
  set("limbs", ({ "鳳喙","鳳爪","鳳身","鳳翅","鳳尾" }) );
  set("age", 500);
  set("force_factor", 30);
  set("combat_exp", 3000000);
  set("max_kee", 30000);
  set("kee", 30000);
  set("max_gin", 30000);
  set("gin", 30000);
  set("max_sen", 30000);
  set("sen", 30000);
  set("force",50000);
  set("max_force", 50000);
  set("attitude", "peaceful");
  set_skill("parry", 300);
  set_skill("unarmed", 300);
  set_skill("dodge", 300);
  set_skill("move", 300);
  set("chat_chance", 4);
  set("chat_msg", ({
     "咕～咕～嘓～嘓～咕～咕～嘓～～～\n",
  }));
  set_temp("apply/attack",550);
  set_temp("apply/damage",550);
  set_temp("apply/move",550);
  setup();
//  carry_object("/open/doctor/obj/feather");
  set("default_actions", (: call_other, __FILE__,"query_action" :));
  reset_action();
  set_heart_beat(1);
}

mapping query_action()
{
  return action[random(sizeof(action))];
}

void heart_beat()
{
  mixed all;
  object me, ob;
  int i;
  ob = this_object();
  if(!ob||!environment()) return ;
  all = all_inventory(environment(ob));

  if(random(100) < 20+random(20) && ob->is_fighting() && !query_temp("unconcious"))
  {
    message_vision("$N"HIR"突然像發瘋似的開始張口狂吐火焰～～～\n\n"NOR, ob);
    for( i = 0 ; i < sizeof(all) ; i++)
    {
      me = all[i];
      if(random(100) < 20+random(20) && present("delfire-mark",me)) { //針對該令牌所額外增加的福利 by blazakira
        message_vision("（但$n身上的"HIR"絕焰令牌"NOR"忽然紅光大作將火焰吸收，$N見狀楞了一下。）\n\n"NOR, ob,me);
        ob->start_busy(1);
        continue;
      }
      if(me->is_character() && living(me) && me->query("id") != "fire phoenix")
      {
        message_vision("$N"HIR"慘遭$n"HIR"所吐出的火球轟中，身上皮膚呈現焦黑一片，使$N"HIR"感到痛苦不已...\n"NOR, me, ob);
        me->add("kee",-150);
        COMBAT_D->report_status(me);
        message_vision("$N"HIR"慘遭$n"HIR"所吐出的火球轟中，身上皮膚呈現焦黑一片，使$N"HIR"感到痛苦不已...\n"NOR, me, ob);
        me->add("kee",-200);
        COMBAT_D->report_status(me);
        message_vision("$N"HIR"慘遭$n"HIR"所吐出的火球轟中，身上皮膚呈現焦黑一片，使$N"HIR"感到痛苦不已...\n"NOR, me, ob);
        me->add("kee",-250);
        COMBAT_D->report_status(me);
        message_vision("$N"HIR"慘遭$n"HIR"所吐出的火球轟中，身上皮膚呈現焦黑一片，使$N"HIR"感到痛苦不已...\n"NOR, me, ob);
        me->add("kee",-250);
        me->add("gin",-150);
        me->add("sen",-150);
        COMBAT_D->report_status(me);
        message_vision("$N"HIR"慘遭$n"HIR"所吐出的火球轟中，身上皮膚呈現焦黑一片，使$N"HIR"感到痛苦不已...\n"NOR, me, ob);
        me->add("kee",-500);
        me->add("gin",-250);
        me->add("sen",-250);
        me->add("force",-800);
        me->start_busy(2);
        me->apply_condition("burn", random(15)+3);
        COMBAT_D->report_status(me);
        message_vision("\n$N"HIB"口中所吐出的火焰慢慢的消失，對$n的攻擊也漸漸的平靜了下來...\n\n"NOR, ob, me);
        ob->start_busy(1);
      }
    }
  }
  ::heart_beat();
}

void init()
{
  add_action("do_pluck","pluck");
}

int do_pluck(string arg)
{
  object me, ob, fea, pnx;
  int kar, spi;

  me = this_player();
  ob = this_object();
  kar = me->query_kar()*2;
  spi = me->query_spi()*2;
  spi = kar+spi;
  if(spi >= 80)
  spi = 80;

  if(!arg || arg != "feather") return 0;
  if(me->query("doctor/get_fea",1))
  {
    message_vision(RED"$N貪心的想再拔第二次...不料卻被"HIR"赤羽火鳳"NOR+RED"給發覺......\n"NOR, me);
    ob->kill_ob(me);
    return 1;
  }
  if(me->query("doctor/get_key",1))
  {
    message_vision(RED"$N偷偷的靠近"HIR"赤羽火鳳"NOR+RED"......\n"NOR, me);
    if(random(100) > spi)
    {
      message_vision(HIB"$N成功\的將$n"HIB"的尾羽給拔到手了！\n"NOR, me, ob);
      me->delete("doctor/get_key");
      me->set("doctor/get_fea",1);
      fea = new("/open/doctor/obj/feather");
      fea->move(me);
      return 1;
    }else{
      message_vision(MAG"$N的動作太大，竟然被$n"MAG"給發覺了！\n"NOR, me, ob);
      ob->kill_ob(me);
      return 1;
    }
  }
}
void die()
{
  object winner = query_temp("last_damage_from");
/* //既然原始沒有開放的計畫就先拿掉了 等要開放時 再來考慮 by blazakira
  if(winner) {
    tell_object(users(), HIR"忽然從瀧山派聖地傳出一聲悲鳴，瀧山聖獸－赤羽火鳳被"+winner->query("name")+HIR"給親手殺死了！"NOR"\n\n"
      +winner->query("name")+HIC"看著"HIR"赤羽火鳳"HIC"臨死前浴火飛行的景狀，瞬間領悟到了"HIR"【火鳳翔空】"HIC"的絕技！\n"NOR);
//    winner->set("doctor/killpnx",1);
  }
*/
  message_vision(HIR"\n赤羽火鳳"NOR+HIW"臨死之際掉落一片閃爍亮麗的羽毛，而身體卻逐漸黯淡……\n\n"NOR,this_object());
  new("/open/doctor/obj/feather")->move(environment(this_object()));
  :: die();
}
