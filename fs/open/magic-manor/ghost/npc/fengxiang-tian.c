//修正狀態名(condition)錯誤 no_plwer >> no_power 且補上receive_wound的攻擊方參數 by blazakira 2011/6/24

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("鳳翔天",({"fengxiang tian","fengxiang","tian"}));
  set("long",@LONG
聚靈山莊的莊主，為人和善，對武學的領略更是古今無人能望
其項背，對於各派的武學瞭然於胸，善長各大派的武學，均有
不凡的領略，武功更是冠絕群倫，達到無敵的狀態。身體中更
是薀含了五行靈魄，配合五轉聚靈盤，能自由運用五行的氣息
達到攻敵與防身的效果。

LONG);

  set("gender","男性");
  set("class","blademan");
  set("nickname",HBBLU+HIC + "天" + HIR + "人合" + HIC + "一" + NOR);
  set("title",HIC + "聚靈莊主" + NOR);
  set("family/family_name","金刀門");
  set("combat_exp",20000000);
  set("attitude","friendly");
  set("score",1000000);
  set("bellicosity",20000);
  set("potential",50000);
  set("age",45);

  set("str", 35);
  set("cor", 35);
  set("cps", 35);
  set("int", 35);
  set("spi", 35);
  set("per", 35);
  set("kar", 35);
  set("con", 35);

  set("env/fan_auto_shoot","YES");
  set("env/飄陽扇連擊","YES");
  set("env/六絕劍","YES");
  set("env/魔性六斬","YES");
  set("env/邪刀連擊","YES");
  set("env/get_mblade","YES");
  set("env/天驚地動",5);
  set("env/superforce","green");
  set("env/連擊","YES");

  set("force",500000);
  set("max_force",50000);
  set("mana",50000);
  set("max_mana",50000);
  set("atman",50000);
  set("max_atman",50000);
  set("force_factor", 35);

  set("s_kee",5000);
  set("max_s_kee",5000);
  set("sec_kee","god");

  set("max_kee",250000);
  set("max_gin",250000);
  set("max_sen",250000);

  set_skill("sword",150);
  set_skill("move",350);
  set_skill("dodge",300);
  set_skill("parry",300);
  set_skill("force",350);
  set_skill("literate",120);
  set_skill("throwing",150);
  set_skill("unarmed",150);
  set_skill("dagger",150);
  set_skill("magic",100);
  set_skill("blade",150);
  set_skill("stabber",150);

  set_skill("shasword",150);
  set_skill("sun_fire_sword",150);
  set_skill("rain-throwing",150);
  set_skill("dreamdance",100);
  set_skill("dremagic",100);
  set_skill("dragon-blade",150);
  set_skill("shadow-kill",150);
  set_skill("canon",100);
  set_skill("universe",150);
  set_skill("counter",150);
  set_skill("badstrike",150);
  set_skill("fast-blade",150);
  set_skill("gold-blade",150);
  set_skill("six-fingers",150);

  set_skill("sha-steps",250);
  set_skill("shade-steps",250);
  set_skill("paull-steps",250);
  set_skill("shift-steps",250);
  set_skill("ghost-steps",250);
  set_skill("linpo-steps",250);

  set_skill("fireforce",300);
  set_skill("fiendforce",300);
  set_skill("blackforce", 300);
  set_skill("dreamforce",300);
  set_skill("superforce", 300);
  set_skill("badforce",300);
  set_skill("sunforce", 300);
  set_skill("sixforce",300);

  map_skill("dodge","linpo-steps");
  map_skill("move","paull-steps");
  map_skill("force","fiendforce");
  map_skill("parry","gold-blade");

  map_skill("blade","fast-blade");
  map_skill("sword","sun_fire_sword");
  map_skill("throwing","rain-throwing");
  map_skill("dagger","shadow-kill");
  map_skill("magic","dremagic");
  map_skill("unarmed","universe");

  set("functions/addbasic/level",100);
  set("functions/addblade/level",100);
  set("functions/badup/level",50);
  set("functions/badroar/level",100);
  set("functions/black/level",150);
  set("functions/blood/level",150);
  set("functions/bluesea/level",150);
  set("functions/busy/level",100);
  set("functions/enforceup/level",100);
  set("functions/evil-blade/level",100);
  set("functions/fan-finger/level",120);
  set("functions/fast-dest/level",100);
  set("functions/fight/level",100);
  set("functions/gen/level",150);
  set("functions/gold-dest/level",100);
  set("functions/gold-fire/level",100);
  set("functions/goldsun/level",150);
  set("functions/green/level",150);
  set("functions/gwe_jen/level",150);
  set("functions/handwriting/level",100);
  set("functions/healup/level",100);
  set("functions/hurtkee/level",100);
  set("functions/hwa_je/level",150);
  set("functions/ice/level",150);
  set("functions/losehurt/level",100);
  set("functions/manakee/level",150);
  set("functions/mdragon-dest/level",100);
  set("functions/mk-blade/level",100);
  set("functions/mobkee/level",150);
  set("functions/nine/level",150);
  set("functions/power-dest/level",100);
  set("functions/powerup/level",100);
  set("functions/purple/level",150);
  set("functions/rainbow-steps/level",100);
  set("functions/sha_kee/level",100);
  set("functions/swordkee/level",100);
  set("functions/sunswordkee/level",100);
  set("functions/tengin/level",100);
  set("functions/white/level",150);
  set("functions/leaf-blade/level",100);

  set("spells/reflection/level",100);
  set("spells/confuse/level",100);
  set("spells/fireball/level",100);
  set("spells/thunder/level",100);
  set("spells/fdragon/level",100);
  set("spells/firedance/level",100);
  set("spells/dreamwings/level",100);
  set("spells/hellfire/level",100);
  set("spells/dreamcure/level",100);

  set("quests/sunfire",1);
  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);
  set("quest/sun_fire_sword",1);
  set("bounds", 40000);
  set("get_sha_sp", 1);
  set("quest/gold-fire",1);
  set("quest/island",3);
  set("can_use_mobkee",1);
  set("quest/rain",1);
  set("quest/worldpill",1);
  set("quest/gold-fire",1);
  set("mk-blade",1);
  set("m_blade",1);
  set("marks/tengin",1);
  set("quests/badroar",1);
  set("marks/kar",1);
  set("marks/sun-finger",1);
  set("marks/six_sp",3);
  set("six_spsp",1);
  set("allow_fdragon",1);
  set("can_use_cloud",1);

  set("clan_kill",1);
  set("no_hole",1);
  set("no_plan_follow",1);
  set("no_mount",1);
  set("cs",2);
  set_temp("fan-finger",5000);
  set_temp("armor_vs_force",300);
  set_temp("no_die_soon",1);
  set_temp("rob",1); 
  set_temp("no-plan",1);
  set_temp("mount",1);
  set_temp("follow",1);
  set_temp("speed",1);
  set_temp("empty",1);
  set_temp("false",1);
  set_temp("lock-link",1);
  set_temp("six-hurt",1);

  set_temp("magic-manor/goldmagic",1);
  set_temp("magic-manor/woodmagic",1);
  set_temp("magic-manor/watermagic",1);
  set_temp("magic-manor/firemagic",1);
  set_temp("magic-manor/soilmagic",1);

  set_temp("apply/armor",150);
  set_temp("apply/attack",150);
  set_temp("apply/damage",150);
  set_temp("apply/defense",150);

  setup();

  add_money("cash",30);
  carry_object("/open/magic-manor/obj/dark-soul-dagger");
  carry_object("/open/magic-manor/obj/maun-shadow-blade")->wield();
  carry_object("/open/magic-manor/obj/evil-kill-claw");
  carry_object("/open/magic-manor/obj/fon-sky-sword");
  carry_object("/open/magic-manor/obj/hwa-je-icer");
  carry_object("/open/magic-manor/obj/evil-gwe-blade");
  carry_object("/open/magic-manor/obj/fire-color-ribbon");
  carry_object("/open/magic-manor/obj/lin-cloud-fan");
  carry_object("/autoload/open-area/five-turn");
  carry_object("/autoload/sky/peace_neck");
  carry_object("/autoload/sky/night-legging");
  carry_object("/autoload/sky/light_cloak");
}

void greeting(object ob)
{
  object npc=this_object();
  ob=this_player();

  if(!npc || !ob ) return;
  command("wear all");
  set_heart_beat(1);
  return;
}

int accept_kill(object ob)
{
  object me=this_object();
  kill_ob(ob);

  command("cmd god_kee");

  if( me->query("cs") == 2 )
  {
    command("perform blade.fast-dest");
  }
  if( me->query("cs") == 1 )
  {
    if ( random(100) > 50 )
    {
      command("perform force.bluesea3");
    }else{
      command("perform unarmed.tengin");
    }
  }
  if( me->query("cs") == 3 )
  {
    command("perform unarmed.badroar");
  }
  if( me->query("cs") == 4 )
  {
    command("perform stabber.handwriting");
  }
  if( me->query("cs") == 5 )
  {
    command("conjure thunder");
    command("conjure fireball");
    command("conjure fdragon");
  }
  if( me->query("cs") == 6 )
  {
    command("perform blade.mdragon-dest");
    command("hurtkee");
    command("busy");
    command("badup");
  }
  if( me->query("cs") == 7 )
  {
    if( !me->query_temp("usesunsword") )
    {
      map_skill("sword", "sun_fire_sword");
      command("perform sun_fire_sword.sunswordkee");
    }else{
      map_skill("sword", "shasword");
    }
  }
  if( me->query("cs") == 8 )
  {
    command("perform throwing.mobkee");
  }
  return 1;
}

void heart_beat()
{
  object *enemy,me=this_object(),eq,room,tian;
  int i,j,k,l,m,n,mk,kee;

  k = random(100);
  l = random(100);

  if(!me || !environment(me)) return ;
  eq = me->query("equipped");
  mk = me->query("max_kee");
  kee =me->query("kee");
  m = (mk-kee)/25;

  enemy = me->query_enemy();
  i = sizeof(enemy);

  if( me->is_fighting() && me->query("kee") < 5000 )
  {
    command("say 啍～");
    command("say 我知道你們想做什麼事，我會在那裏等你們的!!");
    command("say 哈哈哈～～");
    message_vision(HIY + "鳳翔天說完後便消失在一陣靈光之中，並不小心遺落一樣東西!!\n" + NOR,me);
    if( !me->query("have-new") )
    {
      me->set("have-new",1);
      new("/open/magic-manor/ghost/obj/five-turn-ball")->move(environment(me));
      tian = new("/open/magic-manor/npc/fengxiang-tian");
      tian->move("/open/magic-manor/ghost/road10");
    }
    me->move("/open/magic-manor/manor25");
    call_out("dest",3,me);
    return ;
  }

  if( me->query("bellicosity") < 15000 )
  {
    me->add("bellicosity",5000);
  }
  if( me->query_condition("no_power") )
  {
    me->clear_condition("no_power");
  }
  if( me->query("force_factor") < 30 )
  {
    me->set("force_factor",30);
  }
  if( me->query_temp("magic-manor/goldmagic") == 1 )
  {
    command("suck soul");
    command("turn five");
    command("secure lin-cloud-fan");
    command("secure fire-color-ribbon");
    command("secure evil-gwe-blade");
    command("secure hwa-je-icer");
    command("secure fon-sky-sword");
    command("secure evil-kill-claw");
    command("secure maun-shadow-blade");
    command("secure dark-soul-dagger");
    command("wear all");
  }
//自動回氣部份
  if( !me->is_fighting() )
  {
    map_skill("force","fireforce");
    if( query("force") < 50000 )
      command( "ex 500" );
    if( query("eff_kee") < query("max_kee") )
    { 
      command( "10 exert heal" );
      command( "10 exert heal" );
    }
    if( query("gin") < query("eff_gin") )
    {
      me->receive_curing("gin",750);
      me->receive_heal("gin",750);
    }
    if( query("kee") < query("eff_kee") )
      command( "5 exert recover" );
    if( query("sen") < query("eff_sen") )
    {
      me->receive_curing("sen",750);
      me->receive_heal("sen",750);
    }
//聖火技能部份
    if( !me->query_temp("hwa_je") )
    {
      me->set("class","prayer");
      me->set("family/family_name","聖火教");
      me->delete_temp("is_busy");
      me->delete_busy();
      me->delete_temp("no_power_f");
      me->delete_temp("no_power_e");
      map_skill("force","superforce");
      map_skill("unarmed","universe");
      command("exert hwa_je");
    }
    if( !me->query_temp("mixforce") )
    {
      me->set("class","prayer");
      me->set("family/family_name","聖火教");
      map_skill("force","superforce");
      map_skill("unarmed","universe");
      me->delete_temp("is_busy");
      me->delete_busy();
      me->delete_temp("no_power_f");
      me->delete_temp("no_power_e");
      command("perform force.mixforce");
      me->delete_temp("is_busy");
      me->delete_busy();
    }
//修羅鬥氣
    if( !me->query_temp("fight") )
    {
      map_skill("force", "fiendforce");
      me->delete_temp("is_busy");
      me->delete_busy();
      me->delete_temp("no_power_f");
      me->delete_temp("no_power_e");
      command("perform force.fight");
      me->delete_temp("is_busy");
      me->delete_busy();
      map_skill("force", "superforce");
    }
//刀客部份
    if( !me->query_temp("secondary_weapon") )
    {
      me->set("class","blademan");
      me->set("family/family_name","金刀門");
      map_skill("parry","gold-blade");
      map_skill("blade","fast-blade");
      me->delete_temp("is_busy");
      command("perform blade.mk-blade");
      command("wield mk-blade");
      if(present("cloudy fan",me))
      {
        destruct(present("cloudy fan",me));
      }
      me->delete_temp("is_busy");
      me->delete_busy();
    }
    if( !me->query_temp("addblade") )
    {
      me->set("class","blademan");
      me->set("family/family_name","金刀門");
      map_skill("parry","gold-blade");
      map_skill("blade","fast-blade");
      command("addblade");
    }
    if( !me->query_temp("losehurt") )
    {
      me->set("class","blademan");
      me->set("family/family_name","金刀門");
      map_skill("parry","gold-blade");
      map_skill("blade","fast-blade");
      command("losehurt");
    }
    if( !me->query_temp("addbasic") )
    {
      me->set("class","blademan");
      me->set("family/family_name","金刀門");
      map_skill("parry","gold-blade");
      map_skill("blade","fast-blade");
      command("addbasic");
//    command("powerup");
    }
    if( !me->query_temp("addenforce") )
    {
      me->set("class","blademan");
      me->set("family/family_name","金刀門");
      map_skill("parry","gold-blade");
      map_skill("blade","fast-blade");
      command("enfup");
      me->delete_temp("is_busy");
    }
  }
//戰鬥中變化狀態
  if( me->is_fighting() )
  {
    if( present("cloudy fan",me) && me->query("cs") != 4 )
    {
      destruct(present("cloudy fan",me));
    }
//變換門派技能部份
    if( k == 5 || k == 9 )
    {
      me->set("class","prayer");
      me->set("family/family_name","聖火教");
      me->set("cs",1);
      map_skill("force","superforce");
      map_skill("dodge","shift-steps");
      map_skill("move","shift-steps");
      map_skill("parry","universe");
      map_skill("unarmed","universe");
//強迫武器更換成功
      me->delete_busy();
      command("unwield all");
      me->delete_busy();
      command("wield hwa-je-icer");
    }
    if( k == 15 || k == 19 )
    {
      me->set("class","blademan");
      me->set("family/family_name","金刀門");
      me->set("cs",2);
      map_skill("parry","gold-blade");
      map_skill("blade","fast-blade");
      me->delete_busy();
      command("unwield all");
      me->delete_busy();
      command("wield maun-shadow-blade");
    }
    if( k == 25 || k == 29 )
    {
      me->set("class","bandit");
      me->set("family/family_name","惡人谷");
      me->set("cs",3);
      map_skill("unarmed", "badstrike");
      map_skill("parry", "badstrike");
      map_skill("force", "badforce");
      map_skill("dodge", "ghost-steps");
      map_skill("move", "ghost-steps");
      me->delete_busy();
      command("unwield all");
      me->delete_busy();
      command("wield evil-kill-claw");
    }
    if( k == 35 || k == 39 )
    {
      if( me->query("cs") == 4 )
      {
        command("wield all");
      }else{
        me->set("class","scholar");
        me->set("family/family_name","段家");
        me->set("cs",4);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("stabber","six-fingers");
        map_skill("unarmed","six-fingers");
        new("/open/ping/obj/cloud_fan")->move(me);
        me->delete_busy();
        command("unwield all");
        me->delete_busy();
        command("wield lin-cloud-fan");
      }
    }
    if( k == 45 || k == 49 )
    {
      me->set("class","dancer");
      me->set("family/family_name","夜夢小築");
      me->set("cs",5);
      map_skill("magic","dremagic");
      map_skill("dodge","paull-steps");
      map_skill("force","dreamforce");
      map_skill("move","paull-steps");
      map_skill("unarmed","dreamdance");
      me->delete_busy();
      command("unwield all");
      me->delete_busy();
      command("wield fire-color-ribbon");
    }
    if( k == 55 || k == 59 )
    {
      me->set("class","blademan");
      me->set("family/family_name","魔刀門");
      me->set("cs",6);
      map_skill("parry","dragon-blade");
      map_skill("blade","dragon-blade");
      map_skill("force","fiendforce");
      me->delete_busy();
      command("unwield all");
      me->delete_busy();
      command("wield evil-gwe-blade");
    }
    if( k == 65 || k == 69 )
    {
      me->set("class","swordsman");
      me->set("family/family_name","仙劍派");
      me->set("cs",7);
      map_skill("dodge","sha-steps");
      map_skill("move","sha-steps");
      map_skill("parry","shasword");
      map_skill("sword","sun_fire_sword");
      map_skill("force","fiendforce");
      me->delete_busy();
      command("unwield all");
      me->delete_busy();
      command("wield fon-sky-sword");
    }
    if( k == 75 || k == 79 )
    {
      me->set("class","killer");
      me->set("family/family_name","黑牙聯");
      me->set("cs",8);
      map_skill("force","blackforce");
      map_skill("dodge","shade-steps");
      map_skill("move","shade-steps");
      map_skill("parry","rain-throwing");
      map_skill("throwing","rain-throwing");
      map_skill("dagger","shadow-kill");
      me->delete_busy();
      command("unwield all");
      me->delete_busy();
      command("wield dark-soul-dagger");
    }
    if( k == 86 || k == 76 || k == 66 || k == 56 || k == 46 || k == 36 || k == 26 )
    {
      message_vision(HIY + "\n$N一陣怒意上升，只見陣陣的氣流旋空飛起，$N的八把武器御空飛起\n" + NOR,me);
      message_vision(HIY + "  並夾帶威力萬均的氣勢，由$N為中心向四周散射，正是一式驚天神技\n\n" + NOR,me);
      message_vision("                  " + HIC + "╭      " + HIM + "翔      " + HIC + "╮            \n" + NOR,me);
      message_vision("            " + HIC + "╭      " + HIM + "天 " + HIW + "═    ═ " + HIM + "夢      " + HIC + "╮      \n" + NOR,me);
      message_vision("      " + HIC + "╭      " + HIM + "舞 " + HIW + "═                ═ " + HIM + "迴      " + HIC + "╮\n" + NOR,me);
      message_vision("        " + HIM + "夜 " + HIW + "═             " + BLINK+HIY + "‧" + NOR + "            " + HIW + "═ " + HIM + "轉   \n" + NOR,me);
      message_vision("      " + HIC + "╰      " + HIM + "舞 " + HIW + "═                ═ " + HIM + "迴      " + HIC + "╯\n" + NOR,me);
      message_vision("            " + HIC + "╰      " + HIM + "天 " + HIW + "═    ═ " + HIM + "夢      " + HIC + "╯      \n" + NOR,me);
      message_vision("                  " + HIC + "╰      " + HIM + "翔      " + HIC + "╯            \n\n" + NOR,me);
      if( i == 1 || random(30) == 7 )
      {
        for( j=0 ; j<i ; j++ )
        {
          if( userp(enemy[j]) )
          {
            if( environment(me) == environment(enemy[j]) )
            {
              message_vision(HIW + "$N的" + NOR + "楓映天蓮劍" + NOR+HIW + "疾射而至，眩目的劍光造成$n無法逼視。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("no_power",enemy[j]->query_condition("no_power")+5);
              COMBAT_D->report_status(enemy[j]);

              message_vision(HIW + "$N的" + NOR+YEL + "凌微雲扇飄" + NOR+HIW + "疾射而至，刁鑽的氣勁奔向$n各大要穴。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("blockade",enemy[j]->query_condition("blockade")+5);
              COMBAT_D->report_status(enemy[j]);

              message_vision(HIW + "$N的" + NOR+RED + "閻匕影螫魂" + NOR+HIW + "疾射而至，詭異的黑火造成$n極度傷害。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("hellfire",enemy[j]->query_condition("hellfire")+5);
              COMBAT_D->report_status(enemy[j]);

              message_vision(HIW + "$N的" + NOR+CYN + "化劫菱歸真" + NOR+HIW + "疾射而至，渾重的氣勁震的$n氣息翻騰。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("tsunami",enemy[j]->query_condition("tsunami")+5);
              COMBAT_D->report_status(enemy[j]);

              message_vision(HIW + "$N的" + NOR+MAG + "雷火彩鳳翔" + NOR+HIW + "疾射而至，熾熱的氣流灼的$n焚身難受。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("burn",enemy[j]->query_condition("burn")+5);
              COMBAT_D->report_status(enemy[j]);

              message_vision(HIW + "$N的" + NOR+BLU + "魔爪混天殺" + NOR+HIW + "疾射而至，冰寒的氣息造成$n痛徹心扉。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("ice",enemy[j]->query_condition("ice")+5);
              COMBAT_D->report_status(enemy[j]);

              message_vision(HIW + "$N的" + NOR+HIB + "刀斬邪元歸" + NOR+HIW + "疾射而至，沉重的刀氣砍的$n氣息混亂。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("ff_poison",enemy[j]->query_condition("ff_poison")+5);
              COMBAT_D->report_status(enemy[j]);

              message_vision(HIW + "$N的" + NOR+GRN + "幔羅刀無影" + NOR+HIW + "疾射而至，輕薄的刀氣切的$n遍體鱗傷。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("blade",enemy[j]->query_condition("blade")+5);
              COMBAT_D->report_status(enemy[j]);
            }
            if( random(100) > 80 )
            {
              message_vision(HIR + "只見$n承受不了這股強大的神技，應聲被轟飛出廳外了!!\n" + NOR,me,enemy[j]);
              enemy[j]->receive_wound("kee",666,me);
              enemy[j]->receive_wound("gin",333,me);
              enemy[j]->receive_wound("sen",333,me);
              enemy[j]->move("/open/magic-manor/manor02");
            }
          }else{
            enemy[j]->receive_wound("kee",enemy[j]->query("max_kee"),me);
            COMBAT_D->report_status(enemy[j]);
          }
        }
      }else{
        for( j=0 ; j<i ; j++ )
        {
          if( userp(enemy[j]) )
          {
            n = random(8);
            if( environment(me) == environment(enemy[j]) )
            {
              if( n == 0 )
              {
                message_vision(HIW + "$N的" + NOR + "楓映天蓮劍" + NOR+HIW + "疾射而至，眩目的劍光造成$n無法逼視。\n" + NOR,me,enemy[j]);
                enemy[j]->apply_condition("no_power",enemy[j]->query_condition("no_power")+5);
                COMBAT_D->report_status(enemy[j]);
              }
              if( n == 1 )
              {
                message_vision(HIW + "$N的" + NOR+YEL + "凌微雲扇飄" + NOR+HIW + "疾射而至，刁鑽的氣勁奔向$n各大要穴。\n" + NOR,me,enemy[j]);
                enemy[j]->apply_condition("blockade",enemy[j]->query_condition("blockade")+5);
                COMBAT_D->report_status(enemy[j]);
              }
              if( n == 2 )
              {
                message_vision(HIW + "$N的" + NOR+RED + "閻匕影螫魂" + NOR+HIW + "疾射而至，詭異的黑火造成$n極度傷害。\n" + NOR,me,enemy[j]);
                enemy[j]->apply_condition("hellfire",enemy[j]->query_condition("hellfire")+5);
                COMBAT_D->report_status(enemy[j]);
              }
              if( n == 3 )
              {
                message_vision(HIW + "$N的" + NOR+CYN + "化劫菱歸真" + NOR+HIW + "疾射而至，渾重的氣勁震的$n氣息翻騰。\n" + NOR,me,enemy[j]);
                enemy[j]->apply_condition("tsunami",enemy[j]->query_condition("tsunami")+5);
                COMBAT_D->report_status(enemy[j]);
              }
              if( n == 4 )
              {
                message_vision(HIW + "$N的" + NOR+MAG + "雷火彩鳳翔" + NOR+HIW + "疾射而至，熾熱的氣流灼的$n焚身難受。\n" + NOR,me,enemy[j]);
                enemy[j]->apply_condition("burn",enemy[j]->query_condition("burn")+5);
                COMBAT_D->report_status(enemy[j]);
              }      
              if( n == 5 )
              {
                message_vision(HIW + "$N的" + NOR+BLU + "魔爪混天殺" + NOR+HIW + "疾射而至，冰寒的氣息造成$n痛徹心扉。\n" + NOR,me,enemy[j]);
                enemy[j]->apply_condition("ice",enemy[j]->query_condition("ice")+5);
                COMBAT_D->report_status(enemy[j]);
              }
              if( n == 6 )
              {
                message_vision(HIW + "$N的" + NOR+HIB + "刀斬邪元歸" + NOR+HIW + "疾射而至，沉重的刀氣砍的$n氣息混亂。\n" + NOR,me,enemy[j]);
                enemy[j]->apply_condition("ff_poison",enemy[j]->query_condition("ff_poison")+5);
                COMBAT_D->report_status(enemy[j]);
              }
              if( n == 7 )
              {
                message_vision(HIW + "$N的" + NOR+GRN + "幔羅刀無影" + NOR+HIW + "疾射而至，輕薄的刀氣切的$n遍體鱗傷。\n" + NOR,me,enemy[j]);
                enemy[j]->apply_condition("blade",enemy[j]->query_condition("blade")+5);
                COMBAT_D->report_status(enemy[j]);
              }
              if( random(100) > 80 )
              {
                message_vision(HIR + "只見$n承受不了這股強大的神技，應聲被轟飛出廳外了!!\n" + NOR,me,enemy[j]);
                enemy[j]->receive_wound("kee",666,me);
                enemy[j]->receive_wound("gin",333,me);
                enemy[j]->receive_wound("sen",333,me);
                enemy[j]->move("/open/magic-manor/manor02");
              }
            }
          }else{
            enemy[j]->receive_wound("kee",enemy[j]->query("max_kee"),me);
            COMBAT_D->report_status(enemy[j]);
          }
        }
      }
      message_vision(HIC + "\n神技過後，$N顯的有些疲備，仍然從容的收回所有的兵器緊接著出招。\n\n" + NOR,me);
    }
    if( (k == 99 || k == 10 || k == 20 || k == 30 || k == 40 || k == 50 || k == 1) && me->query("kee") > 0 )
    {
      message_vision(HIW + "\n$N周身冉冉泛出五色的靈光球，光球或急或緩的環繞著$N，\n最後排列成一奇怪的三角形狀，印入$N身體中，令$N的身體\n有無不盡的受用。\n\n" + NOR,me);

      me->receive_curing("kee",m);
      me->receive_heal("kee",m);
      me->receive_curing("gin",m);
      me->receive_heal("gin",m);
      me->receive_curing("sen",m);
      me->receive_heal("sen",m);
      me->add("force",m*5);
//      message_vision(HIC + "$N目前回復指數「" + HIM+m+HIC + "」\n" + NOR,me);
    }
//技能攻擊部份
    if( !me->is_busy() )
    {
      if( me->query("cs") == 2 )
      {
        if( !me->query_temp("fast-dest") )
        {
          map_skill("blade", "fast-blade");
          command("perform blade.fast-dest");
        }else{
          map_skill("blade", "gold-blade");
          command("perform blade.gold-dest");
        }
        if( !me->query_temp("badup") )
        {
          command("badup");
        }
        if( !me->query_temp("hurtkee") )
        {
          command("hurtkee");
        }
        if( !me->query_temp("addbusy") )
        {
          command("busy");
        }
      }
      if( me->query("cs") == 1 )
      {
        if ( l > 70 )
        {
          command("perform force.bluesea3");
        }
        if( l < 71 && l > 40)
        {
          set("env/天驚地動",4);
          command("perform unarmed.tengin");
        }
        if( l < 41 && l > 10 )
        {
          set("env/天驚地動",5);
          command("perform unarmed.tengin");
        }
        if( l < 11 )
        {
          command("perform force.gwe_jen");
        }
        if( !me->query_temp("hwa_je") )
        {
          me->delete_temp("is_busy");
          me->delete_busy();
          me->delete_temp("no_power_f");
          me->delete_temp("no_power_e");
          command("exert hwa_je");
        }
      }
      if( me->query("cs") == 3 )
      {
        command("perform unarmed.badroar");
      }
      if( me->query("cs") == 4 )
      {
        command("perform stabber.handwriting");
        if( !query_temp("finger-rest") )
        {
          command("shoot");
        }
      }
      if( me->query("cs") == 5 )
      {
        command("conjure thunder");
        command("conjure fireball");
        if ( l > 30 )
        {
          command("conjure confuse");
        }else{
          command("conjure fdragon");
        }
        if( !me->query_temp("ranbow-steps") )
        {
          me->delete_temp("is_busy");
          me->delete_busy();
          command("perform dodge.rainbow-steps");
        }
      }
      if( me->query("cs") == 6 )
      {
          command("perform blade.mdragon-dest");
        if( !me->query_temp("badup") )
        {
          command("badup");
        }
        if( !query_temp("hurtkee") )
        {
          command("hurtkee");
        }
        if( !query_temp("addbusy") )
        {
          command("busy");
        }
      }
      if( me->query("cs") == 7 )
      {
        if( !me->query_temp("usesunsword") )
        {
          map_skill("sword", "sun_fire_sword");
          command("perform sun_fire_sword.sunswordkee");
        }else{
          map_skill("sword", "shasword");
        }
      }
      if( me->query("cs") == 8 )
      {
        command("perform throwing.mobkee");
      }
    }
  }

  if( me->query("title") != "聚靈莊主" )
  {
    me->set("title",HIC + "聚靈莊主" + NOR);
  }

  set_heart_beat(1);
  ::heart_beat();
}

int dest(object me)
{
  destruct(me);
}
