// 靈刀 by swy
// 做了一些bug的修正，在攻擊的action中，常常會抓不到對方
// 而讓刀失去了心跳，所以修正了一下，若還有其他情形，則會
// 再持續觀察修正，因為刀失去心跳，npc也會跟著失去心跳，而
// 且蠻嚴重的，所以先做了修正，加註於此。 by Neverend 2001/10/14
//增加環境的判斷以避免 【系統】0(0): player:0的錯誤 by blazakira 2011/1/12
//調整gift為新函數應用的形式 by blazakira 2011/7/21

#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit BLADE;
object ob;
object me;
object wname;
object wna;
int mkfun;
int query_autoload() { return 0; }

void create()
{
  set_name("陰靈刀",({"mk-blade"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit","把");
    set("long","一把由內勁與邪氣與陰靈所製成的刀。\n");
    set("value", 0 );
    set("material","crimsonsteel");
    set("wield_msg","$N聚氣凝神內勁一放，頓時陰靈聚集，手中多了一把刀身透明的$n。\n");
    set("unwield_msg","$N內勁一收，頓時陰靈飛散，手中的$n也消失無蹤。\n");
    set("no_sell",1);
    set("no_give",1);
    set("no_save",1);
    set("no_get",1);
    set("no_put",1);
    set("no_auc",1);
  }
  init_blade(1,SECONDARY);
  setup();
}

void init()
{
  object wa;
  ob=this_object();
  me=environment(ob);
  if(!me || !environment(me)) return ;
  wa = present("mk-blade",me);
  if( wa ) {
// 第一層 加刀型
    add_action("do_blade","addblade");
// 第二層 傷害型
    add_action("do_hurt","hurtkee");
// 第三層 busy型
    add_action("do_busy","busy");
// 第四層 heal型
    add_action("do_heal","healup");
// 第五層 enfo型
    add_action("do_enforce","enfup");
// 第六層 攻防型
    add_action("do_power","powerup");
// 第七層 屬性型
    add_action("do_basic","addbasic");
// 第八層 傷減型
    add_action("do_lose","losehurt");
// 第九層 毀器型
    add_action("do_bad","badup");
// 第十層 必殺型
    add_action("do_die","dieup");
  }
}

int do_blade()
{
  int fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/addblade/level");
  wname=me->query_temp("secondary_weapon");
  wna=me->query_temp("weapon");
  if( !wna || ob->query("equipped") != "wielded" )
    return notify_fail("請把武器裝備上。\n");
  if( wna->query("id") == "mk-blade" )
    return notify_fail("此刀要裝備在副武器才有功\效。\n");
  if( me->query("force") < 600 )
    return notify_fail("你的內力不夠。\n");
  if( me->query("bellicosity") < 6 )
    return notify_fail("你的殺氣不夠。\n");
  if( me->query("potential") - me->query("learned_points") < 11 )
    return notify_fail("你的潛能不足以用刀。\n");
  if( me->is_fighting() )
    return notify_fail("戰鬥中不能使用。\n");
  if( me->query_temp("addblade") == 1 )
    return notify_fail("刀之血氣還在你身上遊走。\n");
  message_vision(HIY + "$N手握"+wname->name()+HIY + "，突然一股無窮的力量流入體內。\n" + NOR,me);
  message_vision(HIY + "$N覺的刀法提升了不少。\n" + NOR,me);
  me->add_temp("apply/blade",fun+20);
  me->set_temp("addblade",1);
  me->add("force",-500);
  me->add("bellicosity",-5);
  me->add("potential",-10);
  call_out("delblade",fun+10,me);
  return 1;
}

int delblade(object me)
{
  int fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/addblade/level");
  if(me) {
    me->delete_temp("addblade");
    me->add_temp("apply/blade",-(fun+20));
    message_vision(HIW + "$N覺的刀的血氣消失了。\n" + NOR,me);
    if(fun<100) { function_improved("addblade",random(700)); }
  }
  return 1;
}

int do_hurt()
{
  object *enemy;
  int i,j,fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/hurtkee/level");
  mkfun = me->query("functions/mk-blade/level");
  wname=me->query_temp("secondary_weapon");
  wna=me->query_temp("weapon");
  if( !wna || ob->query("equipped") != "wielded" )
    return notify_fail("請把武器裝備上。\n");
  if( mkfun <= 10 )
    return notify_fail("你的邪靈制刀術還沒到能使用這功\效的等級。\n");
  if( wna->query("id") == "mk-blade" )
    return notify_fail("此刀要裝備在副武器才有功\效。\n");
  if( me->query("force") < 600 )
    return notify_fail("你的內力不夠。\n");
  if( me->query("bellicosity") < 6 )
    return notify_fail("你的殺氣不夠。\n");
  if( me->query("potential") - me->query("learned_points") < 11 )
    return notify_fail("你的潛能不足以用刀。\n");
  if( !me->is_fighting() )
    return notify_fail("要戰鬥中才能使用。\n");
  enemy=me->query_enemy();
  i=sizeof(enemy);
  if(!enemy)
    return notify_fail("沒有敵人可以殺。\n");
  if( me->query_temp("hurtkee") == 1 )
    return notify_fail("你的刀還沒吸滿血氣，再等一下吧。\n");
  message_vision(HIR + "就在$N手持"+wname->name()+HIR + "奮力殺敵時，手中刀身突然地顫抖。\n" + NOR,me);
  for(j=0;j<i;j++) {
    if(!enemy[j]) continue;
    if( (fun*2)+20 > random(250) ) {
    message_vision(HIR + "此刀竟匯集血氣形成血龍，往$N身上啃嗜而去。\n" + NOR,enemy[j]);
    enemy[j]->add("kee",-((fun*12)+350));
    enemy[j]->apply_condition("bleeding",15);
    COMBAT_D->report_status(enemy[j]);
    } else message_vision(HIW + "只見$N起身一跳，驚險的閃避血龍。\n" + NOR,enemy[j]);
  }
  me->set_temp("hurtkee",1);
  me->add("force",-500);
  me->add("bellicosity",-5);
  me->add("potential",-10);
  call_out("delhurt",7,me);
  return 1;
}

int delhurt(object me )
{
  int fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/hurtkee/level");
  if(me) {
    me->delete_temp("hurtkee");
    if(fun<100) { function_improved("hurtkee",random(700)); }
  }
  return 1;
}

int do_busy()
{
  object *enemy;
  int i,j,k,fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/busy/level");
  mkfun = me->query("functions/mk-blade/level");

  if( fun <= 35 )
    k = 1;
  else if( fun >= 36 && fun <= 70 )
    k = 2;
  else if( fun >= 71 )
    k = 3;

  wname=me->query_temp("secondary_weapon");
  wna=me->query_temp("weapon");
  if( !wna || ob->query("equipped") != "wielded" )
    return notify_fail("請把武器裝備上。\n");
  if( mkfun <= 20 )
    return notify_fail("你的邪靈制刀術還沒到能使用這功\效的等級。\n");
  if( wna->query("id") == "mk-blade" )
    return notify_fail("此刀要裝備在副武器才有功\效。\n");
  if( me->query("force") < 600 )
    return notify_fail("你的內力不夠。\n");
  if( me->query("bellicosity") < 6 )
    return notify_fail("你的殺氣不夠。\n");
  if( me->query("potential") - me->query("learned_points") < 11 )
    return notify_fail("你的潛能不足以用刀。\n");
  if( !me->is_fighting() )
    return notify_fail("要戰鬥中才能使用。\n");
  enemy=me->query_enemy();
  i=sizeof(enemy);
  if(!enemy)
    return notify_fail("沒有敵人可以殺。\n");
  if( me->query_temp("addbusy") == 1 )
    return notify_fail("你的刀還沒吸滿血氣，再等一下吧。\n");
  message_vision(HIR + "就在$N手持"+wname->name()+HIR + "奮力殺敵時，手中刀身突然地顫抖。\n" + NOR,me);
  for(j=0;j<i;j++) {
    if(!enemy[j]) continue;
    if( (fun*2)+20 > random(250) ) {
      if( !enemy[j]->is_busy() ) {
        message_vision(HIR + "此刀竟吸收敵人血氣形成血網，封閉了$N的行動。\n" + NOR,enemy[j]);
        enemy[j]->start_busy(k);
        COMBAT_D->report_status(enemy[j]);
      } else message_vision(HIW + "只見$N怒吼一聲發勁抵擋，血網頓時被毀壞殆盡。\n" + NOR,enemy[j]);
    } else message_vision(HIW + "只見$N怒吼一聲發勁抵擋，血網頓時被毀壞殆盡。\n" + NOR,enemy[j]);
  }
  me->set_temp("addbusy",1);
  me->add("force",-500);
  me->add("bellicosity",-5);
  me->add("potential",-10);
  call_out("delbusy",7,me);
  return 1;
}

int delbusy(object me)
{
  int fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/busy/level");
  if(me) {
    me->delete_temp("addbusy");
    if(fun<100) { function_improved("busy",random(700)); }
  }
  return 1;
}

int do_heal()
{
  int fun,n;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/healup/level");
  mkfun = me->query("functions/mk-blade/level");
  wname=me->query_temp("secondary_weapon");
  wna=me->query_temp("weapon");
  if( ob->query("equipped") != "wielded" )
    return notify_fail("請把武器裝備上。\n");
  if( mkfun <= 30 )
    return notify_fail("你的邪靈制刀術還沒到能使用這功\效的等級。\n");
  if(!wna)
    return notify_fail("你沒有裝任何的武器。\n");
  if( wna->query("id") == "mk-blade" )
    return notify_fail("此刀要裝備在副武器才有功\效。\n");
  if( me->query("force") < 600 )
    return notify_fail("你的內力不夠。\n");
  if( me->query("bellicosity") < 6 )
    return notify_fail("你的殺氣不夠。\n");
  if( me->query("potential") - me->query("learned_points") < 11 )
    return notify_fail("你的潛能不足以用刀。\n");
  if( me->is_fighting() )
    return notify_fail("戰鬥中不能使用。\n");
  if( me->query_temp("heal") == 1 )
    return notify_fail("你的刀還沒吸滿血氣，再等一下吧。\n");
  message_vision(HIR + "$N赫然吸取手中"+wname->name()+HIR + "的血氣，此景像異常駭人。\n" + NOR,me);
  message_vision(HIR + "$N吸收完血氣，覺的渾身舒暢無比，筋骨活絡了起來。\n" + NOR,me);
  n = fun*15 + 200;
  me->receive_curing( "gin", n );
  me->receive_heal( "gin", n );
  me->receive_curing("kee",n );
  me->receive_heal("kee",n);
  me->receive_curing("sen",n);
  me->receive_heal("sen",n);
  if( fun >= 95) { 
    if(me->query_condition("bleeding")) { me->clear_condition("bleeding"); }
    if(me->query_condition("burn")) { me->clear_condition("burn"); }
    if(me->query_condition("blade")) { me->clear_condition("blade"); }
    if(me->query_condition("u-stial")) { me->clear_condition("u-stial"); }
    if(me->query_condition("cold")) { me->clear_condition("cold"); }
    if(me->query_condition("hart")) { me->clear_condition("hart"); }
    if(me->query_condition("star-stial")) { me->clear_condition("star-stial"); }
    if(me->query_condition("blockade")) { me->clear_condition("blockade"); }
    if(me->query_condition("skyfire")) { me->clear_condition("skyfire"); }
    if(me->query_condition("tsunami")) { me->clear_condition("tsunami"); }
  }
  me->set_temp("heal",1);
  me->add("force",-500);
  me->add("bellicosity",-5);
  me->add("potential",-10);
  call_out("delheal",7,me);
  return 1;
}

int delheal(object me)
{
  int fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/healup/level");
  if(me) {
    me->delete_temp("heal");
    if(fun<100) { function_improved("healup",random(700)); }
  }
  return 1;
}

int do_enforce()
{
  int fun,k;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/enforceup/level");
  mkfun = me->query("functions/mk-blade/level");
  k = fun/10 + 1;
  if( k > 10 )
    k = 10;
  wname=me->query_temp("secondary_weapon");
  wna=me->query_temp("weapon");
  if( ob->query("equipped") != "wielded" )
    return notify_fail("請把武器裝備上。\n");
  if( mkfun <= 40 )
    return notify_fail("你的邪靈制刀術還沒到能使用這功\效的等級。\n");
  if(!wna)
    return notify_fail("你沒有裝任何的武器。\n");
  if( wna->query("id") == "mk-blade" )
    return notify_fail("此刀要裝備在副武器才有功\效。\n");
  if( me->query("force") < 600 )
    return notify_fail("你的內力不夠。\n");
  if( me->query("bellicosity") < 6 )
    return notify_fail("你的殺氣不夠。\n");
  if( me->query("potential") - me->query("learned_points") < 11 )
    return notify_fail("你的潛能不足以用刀。\n");
  if( me->is_fighting() )
    return notify_fail("戰鬥中不能使用。\n");
  if( me->query_temp("addenforce") == 1 )
    return notify_fail("刀之血氣還在你身上遊走。\n");
  message_vision(HIG + "$N赫然吸取手中"+wname->name()+HIG + "的血氣，此景像異常駭人。\n" + NOR,me);
  message_vision(HIG + "$N吸收完血氣，運起自修內功\把血氣凝成血勁，提升自身威力。\n" + NOR,me);
  me->set_temp("oldenforce",me->query("force_factor"));
  me->set_temp("addenforce",1);
  me->set("force_factor",10+k);
  me->add("force",-500);
  me->add("bellicosity",-5);
  me->add("potential",-10);
  call_out("delenforce",fun+10,me);
  return 1;
}

int delenforce(object me)
{
  int fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/enforceup/level");
  if(me) {
    me->delete_temp("addenforce");
    me->set("force_factor",me->query_temp("oldenforce"));
    me->delete_temp("oldenforce");
    message_vision(HIW + "$N覺的刀的血氣消失了。\n" + NOR,me);
    if(fun<100) { function_improved("enforceup",random(700)); }
  }
  return 1;
}

int do_power()
{
  int fun,k;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/powerup/level");
  mkfun = me->query("functions/mk-blade/level");
  wname=me->query_temp("secondary_weapon");
  wna=me->query_temp("weapon");
  k=(int)(fun/10);
  if( k < 1 ) k=1;
  if( ob->query("equipped") != "wielded" )
    return notify_fail("請把武器裝備上。\n");
  if( mkfun <= 50 )
    return notify_fail("你的邪靈制刀術還沒到能使用這功\效的等級。\n");
  if(!wna)
    return notify_fail("你沒有裝任何的武器。\n");
  if( wna->query("id") == "mk-blade" )
    return notify_fail("此刀要裝備在副武器才有功\效。\n");
  if( me->query("force") < 600 )
    return notify_fail("你的內力不夠。\n");
  if( me->query("bellicosity") < 6 )
    return notify_fail("你的殺氣不夠。\n");
  if( me->query("potential") - me->query("learned_points") < 11 )
    return notify_fail("你的潛能不足以用刀。\n");
  if( me->is_fighting() )
    return notify_fail("戰鬥中不能使用。\n");
  if( me->query_temp("addbasic") == 1 && me->query("id")!="swy" )
    return notify_fail("你已經使用增強術了。\n");
  if( me->query_temp("powerup") == 1 )
    return notify_fail("刀之血氣還在你身上遊走。\n");
  message_vision(HIG + "$N吸收手中"+wname->name()+HIG + "的血氣，此景像異常駭人。\n" + NOR,me);
  message_vision(HIG + "$N吸收完血氣，眼睛發紅，整個人狂暴起來。\n" + NOR,me);
  ob->set("nodrop",1);
  me->apply_condition("mkpowerup",k);
  me->add_temp("apply/dodge",-20);
  me->add_temp("apply/move",-20);
  me->add_temp("apply/parry",-20);
  me->add_temp("apply/attack",((fun*2)+30));
  me->set_temp("powerup",1);
  me->add("force",-500);
  me->add("bellicosity",-5);
  me->add("potential",-10);
  return 1;
}

int do_basic()
{
  int fun,k,g;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/addbasic/level");
  mkfun = me->query("functions/mk-blade/level");
  k=(int)(fun/5);
  if( k < 1 ) k=1;
  me->set_temp("setgift-mk/k",k); //紀錄增加的數值 by blazakira
  g=(int)(fun/10);
  if( g < 1 ) g=1;
  wname=me->query_temp("secondary_weapon");
  wna=me->query_temp("weapon");
  if( ob->query("equipped") != "wielded" )
    return notify_fail("請把武器裝備上。\n");
  if( mkfun <= 60 )
    return notify_fail("你的邪靈制刀術還沒到能使用這功\效的等級。\n");
  if(!wna)
    return notify_fail("你沒有裝任何的武器。\n");
  if( wna->query("id") == "mk-blade" )
    return notify_fail("此刀要裝備在副武器才有功\效。\n");
  if( me->query("force") < 600 )
    return notify_fail("你的內力不夠。\n");
  if( me->query("bellicosity") < 6 )
    return notify_fail("你的殺氣不夠。\n");
  if( me->query("potential") - me->query("learned_points") < 11 )
    return notify_fail("你的潛能不足以用刀。\n");
  if( me->is_fighting() )
    return notify_fail("戰鬥中不能使用。\n");
  if( me->query_temp("powerup") == 1 && me->query("id")!="swy" )
    return notify_fail("你已經使用狂暴術了。\n");
  if( me->query_temp("addbasic") == 1 )
    return notify_fail("刀之血氣還在你身上遊走。\n");
  if( me->query("setgift-mk")==1 )
    return notify_fail("你身上還留著刀之血氣。\n");
  if( me->query_temp("setgift-mk/on")==1 )
    return notify_fail("你身上還留著刀之血氣。\n");
  message_vision(HIG + "$N吸收手中"+wname->name()+HIG + "的血氣，此景像異常駭人。\n" + NOR,me);
  message_vision(HIG + "$N吸收完血氣，血氣遊走全身，使得$N筋骨一陣爆響。\n" + NOR,me);
/*
  me->set("setgift-mk",1);
  me->set("setgift/str",me->query_str());
  me->set("setgift/cps",me->query_cps());
  if(me->query("cloak_add_gift")) me->set("setgift/cps",me->query("origional_cps"));
  me->set("setgift/cor",me->query_cor());
  if(me->query("armband_add_gift")) me->set("setgift/cor",me->query("origional_cor"));
  me->set("setgift/int",me->query_int());
  me->set("setgift/spi",me->query_spi());
  if(me->query("plate_add_gift")) me->set("setgift/spi",me->query("origional_spi"));
  me->set("setgift/kar",me->query_kar());
  if(me->query("legging_add_gift")) me->set("setgift/kar",me->query("origional_kar"));
  me->add("str",k);
  me->add("cps",k);
  me->add("cor",k);
  me->add("int",k);
  me->add("spi",k);
  me->add("kar",k);
*/
  me->set_temp("setgift-mk/on",1);
  me->add_temp("apply/str",k);
  me->add_temp("apply/cps",k);
  me->add_temp("apply/cor",k);
  me->add_temp("apply/int",k);
  me->add_temp("apply/spi",k);
  me->add_temp("apply/kar",k);
  ob->set("nodrop",1);
  me->apply_condition("giftout",g);
  me->set_temp("addbasic",1);
  me->add("force",-500);
  me->add("bellicosity",-5);
  me->add("potential",-10);
  return 1;
}

int do_lose()
{
  int fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/losehurt/level");
  mkfun = me->query("functions/mk-blade/level");
  wname=me->query_temp("secondary_weapon");
  wna=me->query_temp("weapon");
  if( ob->query("equipped") != "wielded" )
    return notify_fail("請把武器裝備上。\n");
  if( mkfun <= 70 )
    return notify_fail("你的邪靈制刀術還沒到能使用這功\效的等級。\n");
  if(!wna)
    return notify_fail("你沒有裝任何的武器。\n");
  if( wna->query("id") == "mk-blade" )
    return notify_fail("此刀要裝備在副武器才有功\效。\n");
  if( me->query("force") < 600 )
    return notify_fail("你的內力不夠。\n");
  if( me->query("bellicosity") < 6 )
    return notify_fail("你的殺氣不夠。\n");
  if( me->query("potential") - me->query("learned_points") < 11 )
    return notify_fail("你的潛能不足以用刀。\n");
  if( me->is_fighting() )
    return notify_fail("戰鬥中不能使用。\n");
  if( me->query_temp("losehurt") == 1 )
    return notify_fail("刀之血氣還在你身上遊走。\n");
  message_vision(HIG + "$N赫然吸取手中"+wname->name()+HIG + "的血氣，此景像異常駭人。\n" + NOR,me);
  message_vision(HIG + "$N吸收完血氣，運功\加勁一吐，其血氣依附$N的身形形成一件『" + HIR + "血氣鬥鎧" + HIG + "』。\n" + NOR,me);
  me->set_temp("losehurt",1);
  me->apply_condition("bloodcloth",10);
  me->add("force",-500);
  me->add("bellicosity",-5);
  me->add("potential",-10);
  call_out("dellose",fun+10,me);
  return 1;
}

int dellose(object me)
{
  int fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/losehurt/level");
  if(me) {
    me->apply_condition("bloodcloth",0);
    me->delete_temp("losehurt");
    message_vision(HIW + "$N覺的刀的血氣消失了。\n" + NOR,me);
    if(fun<100) { function_improved("losehurt",random(700)); }
  }
  return 1;
}

int do_bad()
{
  object target,obt;
  int fun,k;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/badup/level");
  mkfun = me->query("functions/mk-blade/level");
  wname=me->query_temp("secondary_weapon");
  wna=me->query_temp("weapon");
  if( ob->query("equipped") != "wielded" )
    return notify_fail("請把武器裝備上。\n");
  if( mkfun <= 80 )
    return notify_fail("你的邪靈制刀術還沒到能使用這功\效的等級。\n");
  if(!wna)
    return notify_fail("你沒有裝任何的武器。\n");
  if( wna->query("id") == "mk-blade" )
    return notify_fail("此刀要裝備在副武器才有功\效。\n");
  if( !target ) target = offensive_target(me);
  if( !target ) return notify_fail("沒有敵人可以使用。\n");
  if( !me->is_fighting(target) )
    return notify_fail("只能在戰鬥中使用。\n");
  obt=target->query_temp("weapon");
  if( !obt )
    return notify_fail("敵人沒武器。\n");
  if( me->query("force") < 600 )
    return notify_fail("你的內力不夠。\n");
  if( me->query("bellicosity") < 6 )
    return notify_fail("你的殺氣不夠。\n");
  if( me->query("potential") - me->query("learned_points") < 11 )
    return notify_fail("你的潛能不足以用刀。\n");
  if( me->query_temp("badup") == 1 )
    return notify_fail("你的刀還沒吸滿血氣，再等一下吧。\n");
  message_vision(HIY + "就在$N手持"+wname->name()+HIY + "奮力殺敵時，手中刀身突然地顫抖。\n" + NOR,me);
  message_vision(HIY + "只見$N的兵器與$n的兵器相碰在一起發出ㄎ_ㄧ_ㄤ的一聲。\n" + NOR,me,target);
  if( environment(me) == environment(target) ) {
    k=random(fun)+15;
//加上兩個條件下，武器可以免於被損毀，擁有sharp值8以上的武器一定都有特別設計過的
//所以一般原來設計的所有狂想weapon都無法滿足這條件，因為修改過倚天劍和屠龍刀，讓
//這兩把刀劍無法損毀於此特攻下，另外新的我所寫的新區域的mob身上的新武器也有sharp
//值，做了一點點小更動，特別加註於此。  by Neverend 2001/10/14
    if( k > 80 && obt->query("sharp") < 8 && (obt->query("material") != "blacksteel" || obt->query("material") != "crimsonsteel") )
    {
      obt->unequip();
      message_vision(HIR + "只見$N的刀散發出濃稠的血氣，霎然$n的"+obt->query("name")+HIR + "已被溶成二段。\n" + NOR,me,target);
      if( !obt->query("bad"))
      {
        obt->set("name", "(" + HIR + "溶毀" + NOR + ")"+obt->query("name"));
        obt->set("bad",1);
      }
      obt->set("value",1);
      obt->set("weapon_prop/damage",0);
      obt->move(environment(target));
      target->rest_action();
    } else if( obt->query("sharp") < 8 && (obt->query("material") != "blacksteel" || obt->query("material") != "crimsonsteel") ) {
      obt->unequip();
      message_vision(HIR + "只見$N的刀散發出濃綢的血氣，霎然$n的"+obt->query("name")+HIR + "已被血氣侵蝕。\n" + NOR,me,target);
      if( !obt->query("bad"))
      {
        obt->set("name", "(" + HIR + "損壞" + NOR + ")"+obt->query("name"));
        obt->set("bad",1);
      }
      if( obt->query("weapon_prop/damage") >= 15 )
      {
        obt->add("weapon_prop/damage",-15);
        obt->wield();
      } else {
        obt->set("value",1);
        obt->set("weapon_prop/damage",0);
        obt->move(environment(target));
        target->rest_action();
      }
    } else message_vision(HIW + "只見$N與$n的兵器相互碰撞冒出火花。\n" + NOR,me,target);
  }
  me->set_temp("badup",1);
  me->add("force",-500);
  me->add("bellicosity",-5);
  me->add("potential",-10);
  call_out("delbadup",7,me);
  return 1;
}

int delbadup(object me)
{
  int fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/badup/level");
  if(me) {
    me->delete_temp("badup");
    if(fun<100) { function_improved("badup",random(700)); }
  }
  return 1;
}

int do_die()
{
  object target;
  int fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/dieup/level");
  mkfun = me->query("functions/mk-blade/level");
  wname=me->query_temp("secondary_weapon");
  wna=me->query_temp("weapon");
  if( ob->query("equipped") != "wielded" )
    return notify_fail("請把武器裝備上。\n");
  if( mkfun != 100 )
    return notify_fail("你的邪靈制刀術還沒到能使用這功\效的等級。\n");
  if(!wna)
    return notify_fail("你沒有裝任何的武器。\n");
  if( wna->query("id") == "mk-blade" )
    return notify_fail("此刀要裝備在副武器才有功\效。\n");
  if( !target ) target = offensive_target(me);
  if( !target ) return notify_fail("沒有敵人可以使用。\n");
  if( !me->is_fighting(target) )
    return notify_fail("只能在戰鬥中使用。\n");
  if( userp(target) )
    return notify_fail("不能對玩者使用。\n");
  if( target->query_temp("todie") > 1 )  //原本是寫 ==2 會有bug  修正之 by frequency 2003 January
    return notify_fail("同一敵人只能用二次。\n");
  if( target->query_temp("no_die_soon") == 1 )
    return notify_fail("你的必殺一擊對他無效。\n");
  if( me->query("force") < 600 )
    return notify_fail("你的內力不夠。\n");
  if( me->query("bellicosity") < 6 )
    return notify_fail("你的殺氣不夠。\n");
  if( me->query("potential") - me->query("learned_points") < 11 )
    return notify_fail("你的潛能不足以用刀。\n");
  if( me->query_temp("dieup") == 1 )
    return notify_fail("你正在使用。\n");
  message_vision(HIR + "$N赫然吸取手中"+wname->name()+HIR + "的血氣，此景像異常駭人。\n\n" + NOR,me);
  message_vision(HIG + "$N吸收完血氣，把所有血氣與內勁溶合，吐納丹田，似乎要給$n致命一擊。\n\n" + NOR,me,target);
  me->set_temp("dieup",1);
  call_out("deldie",7,me,target);
  return 1;
}

int deldie( object me, object target )
{
  int fun;
  if(!me || !environment(me)) return ;
  fun = me->query("functions/dieup/level");
  me->delete_temp("dieup");
  if( !me || !target ) return 1;
  if( environment(me) != environment(target) ) return 1;
  if( !me->is_fighting(target) ) return 1;
  message_vision( HIY + "\n$N目露兇光大喝道: 看我的『" + HIB + "無亟魔道" + HIY + "』。\n\n", me );
  message_vision( HIR + "只見$N聚集非常強大的血氣勁往$n要害直攻過去。\n\n", me, target );

  if( fun+15 > random(380) ) {
    message_vision( HIM + "$N被強大的血氣勁爆體而過, 當場慘死。\n\n" + NOR, target );
    target->set_temp( "last_damage_from", me );
    target->die();
  }
  else {
    message_vision( HIC + "$N見機運起最強氣勁, 試圖把血氣勁給反擊回去。\n\n", target );
    message_vision( HIB + "不料血氣勁被$N反彈回來, 擊中到$n身上, 頓時, 嚴重受傷失去六分之五的血氣。\n\n" + NOR, target, me );
    target->add_temp( "todie", 1 );
    me->start_busy(2);
    me->add( "kee", -(me->query("kee")*5/6) );
  }

  me->add( "force", -500 );
  me->add( "bellicosity", -5 );
  me->add( "potential", -10 );
  if( fun<100 )
    function_improved( "dieup", random(700) );
  return 1;
}
