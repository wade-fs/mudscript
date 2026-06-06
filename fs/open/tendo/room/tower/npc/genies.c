//排版 by blazakira 2013/9/8
#include <ansi.h>
#include <combat.h>
inherit NPC;
#define bell_big 400
#define bell_small 200
#define SPELLLVL 100
#define MANACOST 150
#define INVCOST 18

int special_att ();
object room2;

void create()
{
  set("title","冥殿殿士");
  set_name("小妖",({"genies"}));
  set("max_gin",1000);
  set("gin",1000);
  set("race","野獸");
  set("age",510);
  set("str", 55);
  set("max_kee", 1000);
  set("kee", 1000);
  set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
  set("verbs", ({ "bite"}));
  set("combat_exp",250000);
  set("attitude","aggressive");
  set_temp("apply/armor",50);
  set_temp("apply/attack", 50);
  set("force_factor",10);
  set("bellicosity",1000);
  set("max_sen",1000);
  set("sen",1000);
  set("max_atman",1000);
  set("atman",1000);
  set("max_mana",1000);
  set("mana",1000);
  set("max_force",1500);
  set("force",1500);
  set("cor", 40);
  set("cps", 25);

  set("chat_chance_combat",25);
  set ("chat_msg_combat", ({(: special_att :)}));

  command("wield all");
  command("wear all");
  set_skill("hell-evil",70);
  map_skill("parry","hell-evil");
  set("unarmed",70);
  map_skill("unarmed","hell-evil");
  set_skill("dodge",70);
  set_skill("fly-steps", 60);
  map_skill("dodge","fly-steps");
  set_skill("parry",70);
  set_temp("mark/up_ng",1); //禁止進入recall區域 by blazakira 2013/9/9
  setup();
  add_money("gold",5);
}

int spell ()
{
  return SPELLLVL;
}

int manacost ()
{
  return MANACOST;
}

int invcost ()
{
  return INVCOST;
}

int special_att ()
{
  object me = this_object ();
  object *enemy = query_enemy (), victim;
  int i = sizeof (enemy), damage;
  victim = enemy[random(i)];
  message_vision(HIB+
     "          －－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  一  式 －－" + NOR + "
                  " + HIB + "～『  " + HIY + "妖 魔 聚 鼎" + HIB + "  』～" + NOR + "
          " + HIW + "冥殿小妖身形倏而騰飛三丈,凌空劈出一" + NOR + "
    " + HIW + "股掌勁,綿綿掌影,如江河缺堤似,暴瀉而下,掌風如激流" + NOR + "
                  " + HIW + "般地向你隔空劈來!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  二  式 －－" + NOR + "
                  " + HIB + "～『  " + HIR + "魔 性 狂 發" + HIB + "  』～" + NOR + "
          " + HIW + "冥殿小妖滿頭銀髮迎風如濤,雙目吐光如炬," + NOR + "
    " + HIW + "忽然雙臂抖舞,幻化成千百條手臂,每一條手臂撲出一般渾" + NOR + "
             " + HIW + "雄的掌風,慢天的掌影向你捲劈而來!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  三  式 －－" + NOR + "
                  " + HIB + "～『  " + HIW + "鬼 氣 貫 腦" + HIB + "  』～" + NOR + "
          " + HIW + "冥殿小妖雙手暴長，臉部青絲暴露，濃烈的惡" + NOR + "
    " + HIW + "臭從雙掌透出，只見冥殿小妖雙手不停疾舞，勁氣中夾帶著" + NOR + "
  " + HIW + "令人聞之欲嘔的毒氣,使得你受到毒氣的影響，受到不輕的傷害!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  四  式 －－" + NOR + "
                  " + HIB + "～『  " + HIC + "魑 魅 魍 魎" + HIB + "  』～" + NOR + "
          " + HIW + "冥殿小妖一聲龍吟般的長嘯,挫身飛騰,身形盪" + NOR + "
    " + HIW + "空迴舞,一連串動作在同一石火電光之間完成,自不同的方向," + NOR + "
  " + HIW + "不同的角度,那宛如似厲鬼魔爪般的掌影,向你詭異奇絕的飛劈而至!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  五  式 －－" + NOR + "
                  " + HIB + "～『  " + MAG + "鬼 魅 拜 月" + HIB + "  』～" + NOR + "
          " + HIW + "只見冥殿小妖身形一躬，雙掌前劈，一道半月" + NOR + "
    " + HIW + "形的勁氣猛然向前湧去，雄渾的勁氣，刮得地面如飛沙走石般" + NOR + "
                       " + HIW + "地向你狂襲而去!!\n"+NOR,me);
  
  if (random (2) >= 1)
  {
    damage = 30+(victim->query ("max_kee") / 8);
    if (damage < 40)
      damage = 40;
    if (damage > 250)
      damage = 250;
    message_vision(HIR + "$N不幸被掌風劈中 , 頓時全身血如泉湧.\n" + NOR,victim);
    victim->apply_condition ("bleeding", random (i * i));
    victim->receive_damage ("kee", damage, me);
    COMBAT_D->report_status (victim, 0);
  } else {
    message_vision(HIW + "只可惜離$N差了一點, 劈到地上, 轟的一聲巨響, 地皮頓時裂了開來.\n" + NOR,victim);
  }
  start_busy (1);
  return 1;
}
