//新增銀針門doctor_book quest的關鍵道具的相關動作 by blazakira 2011/1/9
//將add("kee")調整為receive_damage的攻擊參數並補上攻擊方之參數 by blazakira 2011/4/23
//將一個招式訊息形式message_vision()改為tell_room() by blazakira 2011/9/7 //應該是使用color_ring時 npc消失導致的message錯誤 先改回原先設定 並補上enemy[j]是否存在的判斷 by blazakira 2011/9/15
//出現過會莫名死亡的情況 也不會掉落item 暫時先設訊息來紀錄好了 by blazakira 2011/8/28 //訊息使用系統頻道做長期追蹤 by blazakira 2011/10/15
//將掉落item的move函數移至與掉落message_vision()下 避免出現 已經給予item了 卻沒訊息 造成玩家誤以為沒給item的情況 by blazakira 2011/10/15
//將給予獎勵的判斷形式 從enemy = all_inventory( environment(me) ) 改為打倒damp時 有參戰的人才有 by blazakira 2011/10/16
//增加auto kill的動作 模式為心跳判斷時 kill_ob(target[j]) 為範圍型kill by blazakira 2011/11/7

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

int pil=random(100)+1;
/*
   string *o_item = ({
   "sky-stone","peace-stone","emperor-stone","soil-stone","loyal-stone","charity-stone","justice-stone",
   "fire-emblem","wind-emblem","ice-emblem","thunder-emblem","water-emblem","soil-emblem","magic-emblem","light-emblem","cloud-emblem","dark-emblem",
   "fire-feather","water-feather","soft-feather","thunder-feather","light-feather","wind-feather","heart-feather","think-feather",
   "shue-jade","shen-jade","hun-jade","kai-jade","chen-jade","uiw-jade","gii-jade",
   "com-shells","free-shells","growth-shells","rigid-shells","stable-shells","will-shells","wish-shells",
   "desert-diamond","extreme-diamond","forest-diamond","meteor-diamond","moon-diamond","ocean-diamond","prairie-diamond","river-diamond","sky-diamond","starry-diamond","sun-diamond",
   "dragon-order","kylin-order","phoenix-order","tiger-order","turtle-order","deer-order","fox-order","roc-order",
   "spring-wind","summer-wind","autumn-wind","winter-wind","orchid-wind","bamboo-wind","plum-wind","gui-wind",
   "safe-charm","life-charm","happy-charm","happiness-charm","health-charm","lucky-charm","tender-charm","kind-charm",
   "peach-yin","surname-yin","maple-yin","cypress-yin","pine-yin","plum-yin","banyan-yin","fir-yin","palm-yin",
   "red-crystal","black-crystal","blue-crystal","green-crystal","hiblue-crystal","orange-crystal","purple-crystal","white-crystal","yellow-crystal",
   "mango-doll","apple-doll","lemon-doll","guava-doll","banana-doll","grapes-doll","tomato-doll","cherry-doll","orange-doll","litchi-doll","papaya-doll","starfruit-doll","muskmelon-doll","pineapple-doll","strawberry-doll","watermelon-doll",
   });
   */

void create()
{
  set_name("天威滅神",({"damp god","damp","god"}));
  set("long",@LONG
      原為天靈地界的神祇之一，本性善良，但因為修練武學走火入
      魔後，性情大變而做出了不可挽回之事，糟逐出天靈地界，帶
      有一身的強絕本領。

LONG);

  set("gender","男性");
  set("class","blademan");
  set("nickname",HBBLU+HIC + "所" + HIR + "向無" + HIC + "敵" + NOR);
  set("title",HIC + "天靈地界" + NOR);
  set("family/family_name","金刀門");
  set("combat_exp",250000000);
  set("attitude","friendly");
  set("attribute","saint");
  set("score",1000000);
  set("bellicosity",50000);
  set("potential",150000);
  set("age",45);

  set("str", 100);
  set("cor", 100);
  set("cps", 100);
  set("int", 100);
  set("spi", 100);
  set("per", 100);
  set("kar", 100);
  set("con", 100);

  set("env/fan_auto_shoot","YES");
  set("env/飄陽扇連擊","YES");
  set("env/六絕劍","YES");
  set("env/魔性六斬","YES");
  set("env/邪刀連擊","YES");
  set("env/get_mblade","YES");
  set("env/天驚地動",5);
  set("env/superforce","green");
  set("env/連擊","YES");

  set("force",5000000);
  set("max_force",150000);
  set("mana",150000);
  set("max_mana",150000);
  set("atman",150000);
  set("max_atman",150000);
  set("force_factor", 70);

  set("s_kee",50000);
  set("max_s_kee",50000);
  set("sec_kee","god");

  set("max_kee",2500000);
  set("max_gin",2500000);
  set("max_sen",2500000);
  set("oldkee",2500000);

  set_skill("sword",150);
  set_skill("move",350);
  set_skill("dodge",300);
  set_skill("parry",300);
  set_skill("force",700);
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

  set_skill("fireforce",500);
  set_skill("fiendforce",500);
  set_skill("blackforce", 500);
  set_skill("dreamforce",500);
  set_skill("superforce", 500);
  set_skill("badforce",500);
  set_skill("sunforce", 500);
  set_skill("sixforce",500);

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
  set("functions/fast-dest/level",150);
  set("functions/fight/level",120);
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
  set("functions/young/level",100);

  set("/spells/reflection/level",100);
  set("/spells/confuse/level",100);
  set("/spells/fireball/level",100);
  set("/spells/thunder/level",100);
  set("/spells/fdragon/level",100);
  set("/spells/firedance/level",100);
  set("/spells/dreamwings/level",100);
  set("/spells/hellfire/level",100);
  set("/spells/dreamcure/level",100);

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
  set("mystery",1);

//  set("have_item",1);

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
  set_temp("five-ball",6);
  set_temp("roared",1);

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
//  carry_object("/autoload/sky/peace_neck")->wear();
  carry_object("/autoload/sky/night-legging")->wear();
  carry_object("/autoload/sky/light_cloak")->wear();
  carry_object("/open/mogi/castle/obj/ninepill")->set_amount(pil);
}

void greeting(object ob)
{
  object npc=this_object();
//  ob=this_player();

  if(!npc || !ob ) return;
  command("wear all");
  set_heart_beat(1);
  return;
}

int accept_object(object me,object ob)
{
  destruct(ob);
  return 1;
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
    } else {
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
    } else {
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
  object *enemy,me=this_object(),eq,ppl,*target;
  int i,j,k,l,m,n,o,mk,kee,okee;
  if(!me || !environment()) return ;
  if( query("kee") < 0 || query("gin") < 0 || query("gen") < 0 ) {
    me->die();
    return ;
  }
  else if( me->query_temp("unconcious") == 1 ) return ;

  k = random(100);
  l = random(100);
  eq = me->query("equipped");
  mk = me->query("max_kee");
  kee = me->query("eff_kee");
  okee = me->query("oldkee");

  target = all_inventory( environment(me) );
  i = sizeof(target);
  for (j=0 ; j < i ; j++)
  {
    if( !target[j] || !query_temp("armor") || !query_temp("weapon") ) continue; // || !query_temp("secondary_weapon")
    else
    {
      if(!target[j]->is_fighting() && target[j]->is_character() && !target[j]->is_corpse() 
          && living(target[j]) && !target[j]->query("mystery") && !target[j]->query_temp("blaz/kon"))
        me->kill_ob(target[j]);
    }
  }

  enemy = me->query_enemy();
  i = sizeof(enemy);
//暫時反饋攻擊者的資料 便於尋找莫名死亡的原因 by blazakira 2011/8/28 //改系統頻道反饋以長期追蹤之
//  ppl=find_player("blazakira");
//  if(ppl && enemy && !ppl->query("env/wn_msg_off")) {
    for( j=0 ; j<i ; j++ )
    {
      if( enemy[j] && !query_temp("enemy_damage/"+enemy[j]->query("id")) )
//        tell_object(ppl,HBCYN+enemy[j]->query("name")+"("+enemy[j]->query("id")+")參與天威滅神的攻擊行動。\n"+NOR);
        CHANNEL_D->do_channel(me,"sys",sprintf("%O",HBCYN+enemy[j]->query("name")+"("+enemy[j]->query("id")+")參與天威滅神的攻擊行動。"+NOR));
      add_temp("enemy_damage/"+enemy[j]->query("id"),1); //避免重複反饋情報
    }
//  }

  o = okee-kee;

  if( o < 200000 )
  {
    m = (mk-kee)/50;
  } else {
    k = 99;
    m = (mk-kee)/2;
  }

  //  message_vision("o="+o+"\n",me);

  me->set("oldkee",kee);
/*
  if( me->query("kee") < 0 || me->query("eff_kee") < 0 )
  {
    set_heart_beat(0);
    ::heart_beat();
    return ;
  }
*/
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
    me->set("force_factor",50);
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
    if( query("force") < 150000 )
      command( "ex 500" );
    if( query("eff_kee") < query("max_kee") )
    { 
      command( "10 exert heal" );
      command( "10 exert heal" );
    }
    if( query("gin") < query("eff_gin") )
    {
      me->receive_curing("gin",2000);
      me->receive_heal("gin",2000);
    }
    if( query("kee") < query("eff_kee") )
      command( "5 exert recover" );
    if( query("sen") < query("eff_sen") )
    {
      me->receive_curing("sen",2000);
      me->receive_heal("sen",2000);
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
    if( !me->query_temp("ashura_fight") )
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
      } else {
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


    for( j=0 ; j<i ; j++ )
    {
      if( userp(enemy[j]) && environment(me) == environment(enemy[j]) )
      {
        enemy[j]->add_temp("sb",1);
      }
    }

    if( k== 96 || k == 86 || k == 76 || k == 66 || k == 56 || k == 46 || k == 36 || k == 26 || k == 16 || k == 6 || k == 77 || k == 55 || k == 33)
    {
      enemy = me->query_enemy();
      i = sizeof(enemy);
      if(!enemy) return;
      message_vision(HIY + "\n$N一陣怒意上升，只見陣陣的氣流旋空飛起，$N的八把武器御空飛起\n" + NOR,me,enemy[0]);
      message_vision(HIY + "  並夾帶威力萬均的氣勢，由$N為中心向四周散射，正是一式驚天神技\n\n" + NOR,me,enemy[0]);
      message_vision("                  " + HIC + "╭      " + HIM + "翔      " + HIC + "╮            \n" + NOR,me,enemy[0]);
      message_vision("            " + HIC + "╭      " + HIM + "天 " + HIW + "═    ═ " + HIM + "夢      " + HIC + "╮      \n" + NOR,me,enemy[0]);
      message_vision("      " + HIC + "╭      " + HIM + "舞 " + HIW + "═                ═ " + HIM + "迴      " + HIC + "╮\n" + NOR,me,enemy[0]);
      message_vision("        " + HIM + "夜 " + HIW + "═             " + BLINK+HIY + "‧" + NOR + "            " + HIW + "═ " + HIM + "轉   \n" + NOR,me,enemy[0]);
      message_vision("      " + HIC + "╰      " + HIM + "舞 " + HIW + "═                ═ " + HIM + "迴      " + HIC + "╯\n" + NOR,me,enemy[0]);
      message_vision("            " + HIC + "╰      " + HIM + "天 " + HIW + "═    ═ " + HIM + "夢      " + HIC + "╯      \n" + NOR,me,enemy[0]);
      message_vision("                  " + HIC + "╰      " + HIM + "翔      " + HIC + "╯            \n\n" + NOR,me);

      if( me->query("cs") == 7 || k == 77 || k == 55 || k == 33 )
      {
        for( j=0 ; j<i ; j++ )
        {
          if( enemy[j] && environment(me) == environment(enemy[j]) )
          {
            if( userp(enemy[j]) )
            {
              message_vision(HIW + "$N的" + NOR + "楓映天蓮劍" + NOR+HIW + "疾射而至，眩目的劍光造成$n無法逼視。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("no_power",enemy[j]->query_condition("no_power")+5);
              enemy[j]->receive_damage("gin",500,me);
              enemy[j]->receive_damage("sen",500,me);
              enemy[j]->receive_damage("kee",500,me);
              COMBAT_D->report_status(enemy[j]);
            } else {
              message_vision(HIW + "$N的" + NOR + "楓映天蓮劍" + NOR+HIW + "疾射而至，眩目的劍光造成$n無法逼視。\n" + NOR,me,enemy[j]);
              enemy[j]->receive_wound("gin",enemy[j]->query("max_gin"),me);
              enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/2,me);
              enemy[j]->receive_wound("sen",enemy[j]->query("max_sen"),me);
              COMBAT_D->report_status(enemy[j],1);
            }
          }
        }
      }
      if( me->query("cs") == 4 || k == 77 || k == 55 || k == 33 )
      {
        for( j=0 ; j<i ; j++ )
        {
          if( enemy[j] && environment(me) == environment(enemy[j]) )
          {
            if( userp(enemy[j]) )
            {
              message_vision(HIW + "$N的" + NOR+YEL + "凌微雲扇飄" + NOR+HIW + "疾射而至，刁鑽的氣勁奔向$n各大要穴。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("blockade",enemy[j]->query_condition("blockade")+5);
              enemy[j]->receive_damage("gin",500,me);
              enemy[j]->receive_damage("sen",500,me);
              enemy[j]->receive_damage("kee",500,me);
              COMBAT_D->report_status(enemy[j]);
            } else {
              message_vision(HIW + "$N的" + NOR+YEL + "凌微雲扇飄" + NOR+HIW + "疾射而至，刁鑽的氣勁奔向$n各大要穴。\n" + NOR,me,enemy[j]);
              enemy[j]->receive_wound("gin",enemy[j]->query("max_gin"),me);
              enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/2,me);
              enemy[j]->receive_wound("sen",enemy[j]->query("max_sen"),me);
              COMBAT_D->report_status(enemy[j],1);
            }
          }
        }
      }
      if( me->query("cs") == 8 || k == 77 || k == 55 || k == 33 )
      {
        for( j=0 ; j<i ; j++ )
        {
          if( enemy[j] && environment(me) == environment(enemy[j]) )
          {
            if( userp(enemy[j]) )
            {
              message_vision(HIW + "$N的" + NOR+RED + "閻匕影螫魂" + NOR+HIW + "疾射而至，詭異的黑火造成$n極度傷害。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("hellfire",enemy[j]->query_condition("hellfire")+5);
              enemy[j]->receive_damage("gin",500,me);
              enemy[j]->receive_damage("sen",500,me);
              enemy[j]->receive_damage("kee",500,me);
              COMBAT_D->report_status(enemy[j]);
            } else {
              message_vision(HIW + "$N的" + NOR+RED + "閻匕影螫魂" + NOR+HIW + "疾射而至，詭異的黑火造成$n極度傷害。\n" + NOR,me,enemy[j]);
              enemy[j]->receive_wound("gin",enemy[j]->query("max_gin"),me);
              enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/2,me);
              enemy[j]->receive_wound("sen",enemy[j]->query("max_sen"),me);
              COMBAT_D->report_status(enemy[j],1);
            }
          }
        }
      }
      if( me->query("cs") == 1 || k == 77 || k == 55 || k == 33 )
      {
        for( j=0 ; j<i ; j++ )
        {
          if( enemy[j] && environment(me) == environment(enemy[j]) )
          {
            if( userp(enemy[j]) )
            {
              message_vision(HIW + "$N的" + NOR+CYN + "化劫菱歸真" + NOR+HIW + "疾射而至，渾重的氣勁震的$n氣息翻騰。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("tsunami",enemy[j]->query_condition("tsunami")+5);
              enemy[j]->receive_damage("gin",500,me);
              enemy[j]->receive_damage("sen",500,me);
              enemy[j]->receive_damage("kee",500,me);
              COMBAT_D->report_status(enemy[j]);
            } else {
              message_vision(HIW + "$N的" + NOR+CYN + "化劫菱歸真" + NOR+HIW + "疾射而至，渾重的氣勁震的$n氣息翻騰。\n" + NOR,me,enemy[j]);
              enemy[j]->receive_wound("gin",enemy[j]->query("max_gin"),me);
              enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/2,me);
              enemy[j]->receive_wound("sen",enemy[j]->query("max_sen"),me);
              COMBAT_D->report_status(enemy[j],1);
            }
          }
        }
      }
      if( me->query("cs") == 5 || k == 77 || k == 55 || k == 33 )
      {
        for( j=0 ; j<i ; j++ )
        {
          if( enemy[j] && environment(me) == environment(enemy[j]) )
          {
            if( userp(enemy[j]) )
            {
              message_vision(HIW + "$N的" + NOR+MAG + "雷火彩鳳翔" + NOR+HIW + "疾射而至，熾熱的氣流灼的$n焚身難受。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("burn",enemy[j]->query_condition("burn")+5);
              enemy[j]->receive_damage("gin",500,me);
              enemy[j]->receive_damage("sen",500,me);
              enemy[j]->receive_damage("kee",500,me);
              COMBAT_D->report_status(enemy[j]);
            } else {
              message_vision(HIW + "$N的" + NOR+MAG + "雷火彩鳳翔" + NOR+HIW + "疾射而至，熾熱的氣流灼的$n焚身難受。\n" + NOR,me,enemy[j]);
              enemy[j]->receive_wound("gin",enemy[j]->query("max_gin"),me);
              enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/2,me);
              enemy[j]->receive_wound("sen",enemy[j]->query("max_sen"),me);
              COMBAT_D->report_status(enemy[j],1);
            }
          }
        }
      }
      if( me->query("cs") == 3 || k == 77 || k == 55 || k == 33 )
      {
        for( j=0 ; j<i ; j++ )
        {
          if( enemy[j] && environment(me) == environment(enemy[j]) )
          {
            if( userp(enemy[j]) )
            {
              message_vision(HIW + "$N的" + NOR+BLU + "魔爪混天殺" + NOR+HIW + "疾射而至，冰寒的氣息造成$n痛徹心扉。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("ice",enemy[j]->query_condition("ice")+5);
              enemy[j]->receive_damage("gin",500,me);
              enemy[j]->receive_damage("sen",500,me);
              enemy[j]->receive_damage("kee",500,me);
              COMBAT_D->report_status(enemy[j]);
            } else {
              message_vision(HIW + "$N的" + NOR+BLU + "魔爪混天殺" + NOR+HIW + "疾射而至，冰寒的氣息造成$n痛徹心扉。\n" + NOR,me,enemy[j]);
              enemy[j]->receive_wound("gin",enemy[j]->query("max_gin"),me);
              enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/2,me);
              enemy[j]->receive_wound("sen",enemy[j]->query("max_sen"),me);
              COMBAT_D->report_status(enemy[j],1);
            }
          }
        }
      }
      if( me->query("cs") == 6 || k == 77 || k == 55 || k == 33 )
      {
        for( j=0 ; j<i ; j++ )
        {
          if( enemy[j] && environment(me) == environment(enemy[j]) )
          {
            if( userp(enemy[j]) )
            {
              message_vision(HIW + "$N的" + NOR+HIB + "刀斬邪元歸" + NOR+HIW + "疾射而至，沉重的刀氣砍的$n氣息混亂。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("ff_poison",enemy[j]->query_condition("ff_poison")+5);
              enemy[j]->receive_damage("gin",500,me);
              enemy[j]->receive_damage("sen",500,me);
              enemy[j]->receive_damage("kee",500,me);
              COMBAT_D->report_status(enemy[j]);
            } else {
              message_vision(HIW + "$N的" + NOR+HIB + "刀斬邪元歸" + NOR+HIW + "疾射而至，沉重的刀氣砍的$n氣息混亂。\n" + NOR,me,enemy[j]);
              enemy[j]->receive_wound("gin",enemy[j]->query("max_gin"),me);
              enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/2,me);
              enemy[j]->receive_wound("sen",enemy[j]->query("max_sen"),me);
              COMBAT_D->report_status(enemy[j],1);
            }
          }
        }
      }
      if( me->query("cs") == 2 || k == 77 || k == 55 || k == 33 )
      {
        for( j=0 ; j<i ; j++ )
        {
          if( enemy[j] && environment(me) == environment(enemy[j]) )
          {
            if( userp(enemy[j]) )
            {
              message_vision(HIW + "$N的" + NOR+GRN + "幔羅刀無影" + NOR+HIW + "疾射而至，輕薄的刀氣切的$n遍體鱗傷。\n" + NOR,me,enemy[j]);
              enemy[j]->apply_condition("blade",enemy[j]->query_condition("blade")+5);
              enemy[j]->receive_damage("gin",500,me);
              enemy[j]->receive_damage("sen",500,me);
              enemy[j]->receive_damage("kee",500,me);
              COMBAT_D->report_status(enemy[j]);
            } else {
              message_vision(HIW + "$N的" + NOR+GRN + "幔羅刀無影" + NOR+HIW + "疾射而至，輕薄的刀氣切的$n遍體鱗傷。\n" + NOR,me,enemy[j]);
              enemy[j]->receive_wound("gin",enemy[j]->query("max_gin"),me);
              enemy[j]->receive_wound("kee",enemy[j]->query("max_kee")/2,me);
              enemy[j]->receive_wound("sen",enemy[j]->query("max_sen"),me);
              COMBAT_D->report_status(enemy[j],1);
            }
          }
        }
      }
      message_vision(HIC + "\n神技過後，$N顯的有些疲備，仍然從容的收回所有的兵器緊接著出招。\n\n" + NOR,me);
//      tell_room(me,HIC + "\n神技過後，$N顯的有些疲備，仍然從容的收回所有的兵器緊接著出招。\n\n" + NOR);
    }
/*
    if( k == 77 || k == 55 || k == 33 )
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

      enemy = me->query_enemy();
      i = sizeof(enemy);

      for( j=0 ; j<i ; j++ )
      {
        if( environment(me) == environment(enemy[j]) )
        {
          if( userp(enemy[j]) )
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
          } else {
            enemy[j]->receive_wound("kee",enemy[j]->query("max_kee"),me);
//            COMBAT_D->report_status(enemy[j]);
          }
        }
      }
      message_vision(HIC + "\n神技過後，$N顯的有些疲備，仍然從容的收回所有的兵器緊接著出招。\n\n" + NOR,me);
    }
*/
    if( (k == 99 || k == 10 || k == 20 || k == 30 || k == 1) && me->query("kee") > 0 )
    {
      message_vision(HIY + "                                              \n" + NOR,me);
      message_vision(HIY + "                        ╰●╯                \n" + NOR,me);
      message_vision(HIY + "                                              \n" + NOR,me);
      message_vision(HIY + "                        ╰●╯                \n" + NOR,me);
      message_vision(HIG + "                    ╰●      ●╯            \n" + NOR,me);
      message_vision(HIG + "                        ╰●╯                \n" + NOR,me);
      message_vision(HIG + "                    ╰●      ●╯            \n" + NOR,me);
      message_vision(HIC + "                ╰●    ╰●╯    ●╯        \n" + NOR,me);
      message_vision(HIC + "                    ╰●      ●╯            \n" + NOR,me);
      message_vision(HIC + "                ╰●    ╰●╯    ●╯        \n" + NOR,me);
      message_vision(HIR + "            ╰●    ╰● ╰╯ ●╯    ●╯    \n" + NOR,me);
      message_vision(HIR + "                ╰● ╰╯    ╰╯ ●╯        \n" + NOR,me);
      message_vision(HIB + "            ╰● ╰╯            ╰╯ ●╯    \n" + NOR,me);
      message_vision(HIB + "        ╰● ╰╯                    ╰╯ ●╯\n" + NOR,me);
      message_vision(HIB + "         ╰╯                            ╰╯ \n" + NOR,me);

      message_vision(HIW + "\n$N周身冉冉泛出五色的靈光球，光球或急或緩的環繞著$N，\n最後排列成一奇怪的三角形狀，印入$N身體中，令$N的身體\n有無不盡的受用。\n\n" + NOR,me);
      me->receive_curing("kee",m+random(m)+random(m));
      me->receive_heal("kee",m+random(m)+random(m));
      me->receive_curing("gin",m+random(m)+random(m));
      me->receive_heal("gin",m+random(m)+random(m));
      me->receive_curing("sen",m+random(m)+random(m));
      me->receive_heal("sen",m+random(m)+random(m));
      me->add("force",m*5);
      me->clear_condition();
      //    message_vision(HIC + "$N目前回復指數「" + HIM+m+HIC + "」\n" + NOR,me);
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
        } else {
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
        } else {
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
        } else {
          map_skill("sword", "shasword");
        }
      }
      if( me->query("cs") == 8 )
      {
        command("perform throwing.mobkee");
      }
    }
  }

  if( me->query("title") != "天靈地界" )
  {
    me->set("title",HIC + "天靈地界" + NOR);
  }

//  set_heart_beat(1);
  ::heart_beat();
}
/*
void unconcious()
{
  object me=this_object();
  if( present("hwa-je-icer",me) );
  {
    destruct(present("hwa-je-icer",me));
  }
  if( present("maun-shadow-blade",me) );
  {
    destruct(present("maun-shadow-blade",me));
  }
  if( present("evil-kill-clae",me) );
  {
    destruct(present("evil-kill-claw",me));
  }
  if( present("lin-cloud-fan",me) );
  {
    destruct(present("lin-cloud-fan",me));
  }
  if( present("fire-color-ribbon",me) );
  {
    destruct(present("fire-color-ribbon",me));
  }
  if( present("evil-gwe-blade",me) );
  {
    destruct(present("evil-gwe-blade",me));
  }
  if( present("fon-sky-sword",me) );
  {
    destruct(present("fon-sky-sword",me));
  }
  if( present("dark-soul-dagger",me) );
  {
    destruct(present("dark-soul-dagger",me));
  }
  if( present("five turn",me) );
  {
    destruct(present("five turn",me));
  }
  if( present("water-light-cloak",me));
  {
    destruct(present("water-light-cloak",me) );
  }
  if( present("night-legging",me));
  {
    destruct(present("night-legging",me) );
  }
//  if( present("peace-heart-neck",me));
//  {
//    destruct(present("peace-heart-neck",me) );
//  }

  :: unconcious();
}
*/
void die()
{
  object ob1,me,winner,ob,ppl;
  mixed enemy;
  string name;
  int a,b,i,j,k,sb,sw,sum;
  int all_war;

//  object winner = query_temp("last_damage_from");
//  string name = winner->query("name");

//  if( !userp(winner) )
//  {
//    :: die();
//  }
  all_war = 2000;
  me=this_object();
/*
魚缸@台北 說:
 call_stack回傳是array
  ppl=find_player("blazakira");
  if(ppl)
    tell_object(ppl,sprintf("%O",call_stack())); //此參數於此處時 可查看造成npc死亡的相關物件來debug by blazakira
*/
  CHANNEL_D->do_channel(me,"sys",sprintf("%O",call_stack()));

/*
魔女洋子（建彰：主機板燒了，又花錢了...orz 說:
 沒經過心跳 跳出戰鬥(flee or ppl die)就會刪除query_enemy()
魚缸@台北 說:
 哪只好用query_enemy(object ob) 看所有的對手有沒有這個敵人
 放過來查
魚缸@台北 說:
 int is_fighting(object ob)
 foreach(object obj in all_invertory(environment(me)) ){
 if(ob->is_fighting( me )) ...
魚缸@台北 說:
 反過來查啊
 看對手有沒有打我
*/
//當玩家使用hero時 就有機率會離開戰鬥狀態而清除身上敵人的紀錄 是以不能使用enemy = me->query_enemy();
//另以上方說明額外在下方做戰鬥反推 by blazakira
//  enemy = me->query_enemy();
  enemy = all_inventory( environment(me) );
  foreach(object obj in all_inventory(me))
  {
    if(strsrch(file_name(obj),"/autoload") != -1 || 
       strsrch(file_name(obj),"/open/magic-manor/") != -1 )
      destruct(obj);
  }

  a=0;
  k=sizeof(enemy);

  i=random(1080);

  if( !me->query("have_item") )
  {
    string *files,file,dir;
    string *dirs = ({
      "obj1",
      "obj2",
      "obj3",
      "obj4",
      "obj5",
      "obj6",
      "obj7",
      "obj8",
      "obj9",
      "obj10",
      "obj11",
      "obj12"
    });
    dir = "/open/sky/"+dirs[random(sizeof(dirs))]+"/";
    while(1) {
      files = get_dir(dir);
      file = files[random(sizeof(files))];
      if(file[0] == '.') continue;
      break;
    }
    sum = 0;
    for( j=0 ; j < k ; j++ )
    {
      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && enemy[j]!=me && environment(this_object())==environment(enemy[j]) )
      {
        // 計算總傷血量
        sum += query_temp("record_damage/"+enemy[j]->query("id") );
      }
    }
/*
    for( j=0 ; j < k ; j++ )
    {
      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && enemy[j]!=me && environment(this_object())==environment(enemy[j]) )
      {

        b = query_temp("record_damage/"+enemy[j]->query("id") );
        sw = all_war * (b/50000) / (sum / 50000 +1) ;

        if( b > a )
        {
          a=b;
          winner=enemy[j];
        }

        if( sw > 400 ) sw=400;

        if( b > 50000  ) // 最少要打到五萬的血..
        {
          enemy[j]->add("standby",1);
          enemy[j]->add("war_score",sw);
          message_vision(HIW + "由於$N的努力，獲得了一個替身及「" + HIM+chinese_number(sw)+HIW + "」點戰功\!!。\n" + NOR,enemy[j]);
          write_file("/log/get_war/damp_god_other",sprintf("%s(%s)得到%s點戰功\於 %s\n",enemy[j]->name(1),enemy[j]->query("id"),chinese_number(sw),ctime(time())));
        } else {
          enemy[j]->add("war_score",sw / 2 );
          message_vision(HIR + "$N的參與度不足，無法獲得替身，但得到「" + HIM+chinese_number(sw)+HIR + "」點戰功\!!\n" + NOR,enemy[j]);
          write_file("/log/get_war/damp_god_other",sprintf("%s(%s)得到%s點戰功\於 %s\n",enemy[j]->name(1),enemy[j]->query("id"),chinese_number(sw/2),ctime(time())));
        }
      }
    }
*/
    message_vision(HIC + "在與"+query("name")+HIC + "的戰鬥後，在場確定參與者：\n" + NOR,me);
    foreach(object obj in all_inventory(environment(me)) ) {
      if( obj->is_fighting( me ) )
        if( obj && userp(obj) && obj->is_character() && !obj->is_corpse() && obj!=me )
        {
          b = query_temp("record_damage/"+obj->query("id") );
          sw = all_war * (b/50000) / (sum / 50000 +1) ;

          if( b > a )
          {
            a=b;
            winner=obj;
          }

          if( sw > 400 ) sw=400;

          if( b > 50000  ) // 最少要打到五萬的血..
          {
            obj->add("standby",1);
            obj->add("war_score",sw);
            message_vision(HIW + "\t由於$N的努力，獲得了一個替身及「" + HIM+chinese_number(sw)+HIW + "」點戰功\!!。\n" + NOR,obj);
            write_file("/log/get_war/damp_god_other",sprintf("%s(%s)得到%s點戰功\於 %s\n",obj->name(1),obj->query("id"),chinese_number(sw),ctime(time())));
          } else {
            obj->add("war_score",sw / 2 );
            message_vision(HIR + "\t$N的參與度不足，無法獲得替身，但得到「" + HIM+chinese_number(sw)+HIR + "」點戰功\!!\n" + NOR,obj);
            write_file("/log/get_war/damp_god_other",sprintf("%s(%s)得到%s點戰功\於 %s\n",obj->name(1),obj->query("id"),chinese_number(sw/2),ctime(time())));
          }
        }
    }

    if(!winner) {
      winner=me; //當玩家使用hero時 很有可能比damp god先死所導致的意外 暫時做此設定 by blazakira
      set("no_winner",1); //作為下方tell_object(users()的判斷 但是不能獲得獎勵 by blazakira
    }
    name = winner->query("name");
    tell_object(users(),HIW + "\n我" + HIR+me->query("name")+HIW + "絕不甘心死在平凡的人類" + HIR+winner->query("name")+HIW + "手中呀！\n\n\t所有狂想空間的人等著瞧！！\n\n\t\t我會再捲土重來的．．．．．\n\n" + NOR);

    if(winner && !winner->query_temp("not_robot") && random(100)==0) {
      ob=new("/open/doctor/doctor_book/obj/scrap");
      ob->set("sort","麟");
      ob->move(winner);
      message_vision(CYN + "\n從"+me->query("name")+"的身上掉下了一塊靈魂碎片!!\n" + NOR,winner);
    }
    else if(winner && winner->query_temp("not_robot") && random(100)<90) {
      ob=new("/open/doctor/doctor_book/obj/scrap");
      ob->set("sort","麟");
      ob->move(winner);
      message_vision(CYN + "\n從"+me->query("name")+"的身上掉下了一塊靈魂碎片!!\n" + NOR,winner);
    }
    if(!me->query("no_winner")) { //額外的判定 出現造成!winner的情況就不給打死的獎勵(或許是npc打死的 而傷害判定只讀取玩家部份 玩家傷害小於5w時) by blazakira
      ob1=new(dir+file);
      ob1->move(environment(me));
      me->set("have_item",1);
      message_vision(HIM + "\n從"+me->name(1)+"的身上掉下了一個「"+ob1->query("name")+HIM + "」!!\n" + NOR,winner,me);
      write_file("/log/sky/war/damp_god",sprintf("%s(%s)	讓%s掉下了%s於 %s\n",winner->name(1),winner->query("id"),me->query("name"),ob1->query("name"),ctime(time())));

      message_vision(HIY + "\n恭喜"+winner->name()+"打死"+me->query("name")+"得到一千點戰功\!!\n" + NOR,winner);
      write_file("/log/get_war/damp_god",sprintf("%s(%s)	得到一千點戰功\於 %s\n",winner->name(1),winner->query("id"),ctime(time())));
      winner->add("war_score",1000);
      winner->add("standby",1);
//      tell_object(winner,HIY + "\n由於你的努力，替身上限額外增加了一個!!\n" + NOR);
      message_vision(HIW + "$N獲得一個替身。\n" + NOR,winner);
    }
  }

  :: die();
}

void record_damage(int damage, object who)
{
  if(!who || who && !userp(who)) return ;
  add_temp("record_damage/"+who->query("id") , damage);
  environment()->add_temp("damp_god/record_damage/"+who->query("id") , damage); //作為追蹤用 by blazakira
}
varargs int receive_damage(string type, int damage, object who)
{
  ::receive_damage(type,damage,who);
  who = query_temp("last_damage_from");
  record_damage(damage,who);
}
varargs int receive_wound(string type, int damage, object who)
{
  ::receive_wound(type,damage,who);
  who = query_temp("last_damage_from");
  record_damage(damage,who);
}
