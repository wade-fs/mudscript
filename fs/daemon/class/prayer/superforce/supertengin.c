//by frequency 2003 4/18
//修正判斷使用者是否存在的錯誤 與補上receive_xxx的攻擊方參數 by blazakira 2011/9/12

#include <ansi.h>
inherit SSERVER;
inherit F_FUNCTION;

void create() { seteuid(getuid()); }

int again_wind(object me);
int again_water(object me);
int again_fire(object me);
int again_mountain(object me);
int again_thunder(object me);
int perform( object me, object target )
{
  object weapon, mob, *enemy;
  int i;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  if(!me->query("advance_prayer"))
    return notify_fail("你尚未參透融合兩大絕學的法門。\n");
  if(me->query("force") < 1000)
    return notify_fail("你的內力不夠。\n");
  if ((int)me->query_temp ("hwa_je", 1))
    return notify_fail ("為求集中力量攻擊，你必須先散去化劫護身勁。\n");
  if( me->query_skill( "universe", 1 ) < 140 )
    return notify_fail( "你的先天乾坤功\還不夠熟練喔。\n" );
  if( me->query_skill_mapped("unarmed") != "universe" )
    return notify_fail( "你必須將先天乾坤功\當作你的攻擊根基。\n" );
  if( me->query_skill( "superforce", 1 ) < 251 )
    return notify_fail( "你尚未參透渾天寶鑑奧秘。\n" );
  if( me->query_skill_mapped("force") != "superforce" )
    return notify_fail( "請以渾天寶鑑為心法來推動此招吧。\n" );
  if( me->query("functions/tengin/level") < 100)
    return notify_fail( "請把天驚地動練熟練點吧!!\n" );
  if( me->query("family/family_name") != "聖火教" )
    return notify_fail( "只有聖火教能用喔。\n" );
  if( !me->is_fighting() )
    return notify_fail( "沒事別亂放絕招，很危險的 :p \n" );
  if( me->query("max_force") < 7000 )
    return notify_fail( "你的內功\根基不足,無法靈活運用天地之氣。\n" );

  if(!me->query_temp("supertengin/wind"))
  {
    message_vision(HIR + "\n$N融合渾天寶鑑和先天乾坤功\的強極力量，使出" + HIY + "『" + HIG + "風兮" + HIW + "白雲煙" + HIY + "』" + HIR + "，現場刮起一道巨大的龍捲風。\n" + NOR,me);
    me->set_temp("supertengin/wind",1);
    call_out("again_wind", 1, me);
    me->add( "force", -200 );
    me->start_busy(1);
    return 1;
  } else {
    if( me->query("functions/supertengin/level") < 30)
      return notify_fail( "你對寰宇渾天勁的領悟尚不足以推動水兮靛滄海。\n" );
    if(!me->query_temp("supertengin/water"))
    {
      message_vision(HIG + "\n$N融合渾天寶鑑和先天乾坤功\的驚人力量，使出" + HIW + "『" + HIC + "水兮" + HIB + "靛滄海" + HIW + "』" + HIG + "，四海之氣如海嘯般瘋狂襲來。\n" + NOR,me);
      me->set_temp("supertengin/water",1);
      call_out("again_water", 1, me);
      me->add( "force", -300 );
      me->start_busy(1);
      return 1;
    } else {
      if( me->query("functions/supertengin/level") < 55)
        return notify_fail( "你對寰宇渾天勁的領悟尚不足以推動火兮紫星河。\n" );
      if(!me->query_temp("supertengin/fire"))
      {
        message_vision(HIY + "\n$N融合渾天寶鑑和先天乾坤功\的滅世力量，使出" + HIC + "『" + HIR + "火兮" + HIM + "紫星河" + HIC + "』" + HIY + "，天火、融岩帶著驚人的高溫湧至。\n" + NOR,me);
        me->add( "force", -370 );
        call_out("again_fire", 1, me);
        me->start_busy(1);
        return 1;
      } else {
        if( me->query("functions/supertengin/level") < 80)
          return notify_fail( "你對寰宇渾天勁的領悟尚不足以推動山兮金晨曦。\n" );
        if(!me->query_temp("supertengin/mountain"))
        {
          message_vision(HIM + "\n$N融合渾天寶鑑和先天乾坤功\的頂級力量，使出" + HIG + "『" + YEL + "山兮" + HIY + "金晨曦" + HIG + "』" + HIM + "，三山五嶽的強大生命力立即籠罩戰場。\n" + NOR,me);
          me->add( "force", -450 );
          call_out("again_mountain", 1, me);
          me->start_busy(1);
          return 1;
        } else {
          if( me->query("functions/supertengin/level") < 100)
            return notify_fail( "你對寰宇渾天勁的領悟尚不足以推動雷兮血穹蒼。\n" );
          if(!me->query_temp("supertengin/thunder"))
          {
            message_vision(HIC + "\n$N解放渾天寶鑑和先天乾坤功\的終極力量，使出" + HIB + "『" + HIM + "雷兮" + HIR + "血穹蒼" + HIB + "』" + HIC + "，血勁天雷逐漸在天上融合，蓄勢待發。\n" + NOR,me);
            me->add( "force", -500 );
            call_out("again_thunder", 1, me);
            me->start_busy(1);
            return 1;
          } else {
            return notify_fail( "將寰宇渾天勁提升到極限之後，你需要片刻時間調養生息。\n" );
          }
        }
      }
    }
  }
}

int again_wind(object me)
{
  object *enemy;
  int i,fun1,fun2,fun,y;
  if(!me) return 1;
  y = me->query("functions/supertengin/level") / 10;
  if(y < 1) y = 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  fun=me->query("functions/supertengin/level");
  fun1=me->query("functions/tengin/level");
  fun2=me->query("functions/white/level");
  if(me->query_temp("supertengin/wind") == y)
  {
    tell_object(me,sprintf(HIW + "你的風兮白雲煙使盡了。\n" + NOR));
    me->delete_temp("supertengin/wind");
    if(fun<120) function_improved("supertengin",random(100));
    return 1;
  }
  while(i--)
  {
    if(!me||!enemy[i]) continue;
    if(random(5) != 3)
    {
      message_vision(HIW + "\n浮雲飛快流轉，颶風狂嘯著將$n狠狠的捲上雲端後，$n重重落下。\n" + NOR,me,enemy[i]);
      if(random(2) == 1)  enemy[i]->start_busy(1);
      enemy[i]->receive_damage("kee",3*(fun1+fun2+fun),me);//最高為810
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIW + "\n$n即時穩住身形，不受颶風影響。\n" + NOR,me,enemy[i]);
      COMBAT_D->report_status(enemy[i]);
    }    
  }
  me->add_temp("supertengin/wind",1);
  call_out("again_wind", 2, me);
  return 1;
}

int again_water(object me)
{
  object *enemy;
  int i,fun,fun1,fun2,y;
  if(!me) return 1;
  y = me->query("functions/supertengin/level") / 10;
  if(y < 1) y = 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  fun=me->query("functions/supertengin/level");
  fun1=me->query("functions/tengin/level");
  fun2=me->query("functions/bluesea/level");
  if(me->query_temp("supertengin/water") == y)
  {
    tell_object(me,sprintf(HIC + "你的水兮靛滄海使盡了。\n" + NOR));
    me->delete_temp("supertengin/water");
    if(fun<120) function_improved("supertengin",random(100));
    return 1;
  }
  while(i--)
  {
    if(!me||!enemy[i]) continue;
    if(random(5) != 3)
    {
      message_vision(HIC + "\n靛滄海氣勁挾帶著五湖四海的力量，如海嘯般衝擊著$n。\n" + NOR,me,enemy[i]);
      if(random(2) == 1)  enemy[i]->start_busy(1);
      enemy[i]->receive_damage("kee",3*(fun1+fun2+fun),me); //最高為960
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIC + "\n$n運勁強抗海嘯衝擊，僅受了點小傷。\n" + NOR,me,enemy[i]);
      enemy[i]->receive_damage("kee",80,me);
      COMBAT_D->report_status(enemy[i]);
    }
  }
  me->add_temp("supertengin/water",1);
  call_out("again_water", 2, me);
  return 1;
}

int again_fire(object me)
{
  object *enemy;
  int i,fun,fun1,fun2,y;
  if(!me) return 1;
  y = me->query("functions/supertengin/level") / 10;
  if(y < 1) y = 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  fun=me->query("functions/supertengin/level");
  fun1=me->query("functions/tengin/level");
  fun2=me->query("functions/purple/level");
  if(me->query_temp("supertengin/fire") == y)
  {
    tell_object(me,sprintf(HIR + "你的火兮紫星河使盡了。\n" + NOR));
    me->delete_temp("supertengin/fire");
    if(fun<120) function_improved("supertengin",random(100));
    return 1;
  }
  while(i--)
  {
    if(!me||!enemy[i]) continue;
    if(random(5) != 3)
    {
      message_vision(HIR + "\n星晨之力，蘊藏融岩天火，吐著紫焰如天譴般吞噬著$n。\n" + NOR,me,enemy[i]);
//      message_vision("傷害值為"+fun2+"加"+fun+"加"+fun1+"。\n" + NOR,me);
      enemy[i]->receive_damage("kee",5*(fun+fun1+fun2),me); //最高為1350
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIR + "\n$n急運最高功\力抵抗星火焚身，縱使避過亦感五內俱焚。\n" + NOR,me,enemy[i]);
      enemy[i]->add("force",-50);
      COMBAT_D->report_status(enemy[i]);
    }    
  }
  me->add_temp("supertengin/fire",1);
  call_out("again_fire", 2, me);
  return 1;
}

int again_mountain(object me)
{
  int fun,fun1,fun2,y;
  if(!me) return 1;
  y = me->query("functions/supertengin/level") / 10;
  if(y < 1) y = 1;
  fun=me->query("functions/supertengin/level");
  fun1=me->query("functions/tengin/level");
  fun2=me->query("functions/goldsun/level");
  if(me->query_temp("supertengin/mountain") == y)
  {
    tell_object(me,sprintf(HIY + "你的山兮金晨曦使盡了。\n" + NOR));
    me->delete_temp("supertengin/mountain");
    if(fun<120) function_improved("supertengin",random(100));
    return 1;
  }
  message_vision(HIY + "\n朝陽，光明之始；大地，萬物之本；無限萬靈之力，生生不息，注入$N身軀。\n" + NOR,me);
  me->receive_heal("kee",fun+fun1+fun2);   //最高為370
  me->receive_curing("kee",fun+fun1+fun2); //最高為370
  me->add("force",random(fun));            //最高為120
  COMBAT_D->report_status(me);
  me->add_temp("supertengin/mountain",1);
  call_out("again_mountain", 2, me);
  return 1;
}

int again_thunder(object me)
{
  object *enemy;
  int i,fun,fun1,fun2,y;
  if(!me) return 1;
  y = me->query("functions/supertengin/level") / 10;
  if(y < 1) y = 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  fun=me->query("functions/supertengin/level");
  fun1=me->query("functions/tengin/level");
  fun2=me->query("functions/blood/level");
  if(me->query_temp("supertengin/thunder") == y)
  {
    tell_object(me,sprintf(HIM + "你的雷兮血穹蒼使盡了。\n" + NOR));
    me->delete_temp("supertengin/thunder");
    if(fun<120) function_improved("supertengin",random(100));
    return 1;
  }
  while(i--)
  {
    if(!me||!enemy[i]) continue;
    if(random(5) != 3)
    {
      message_vision(HIR + "\n穹蒼血勁" + HIW + "、" + HIM + "九天之雷" + HIW + "聚集而成的無數光球，如雨點般不斷擊中$n。\n" + NOR,me,enemy[i]);
      enemy[i]->receive_wound("kee",4*(fun+fun1+fun2),me); //最高為1480
      COMBAT_D->report_status(enemy[i],1);
    } else {
      message_vision(HIM + "\n$n不惜大耗真元，以驚世身法在狹縫中左閃右避，勉強閃過光球的駭人攻勢。\n" + NOR,me,enemy[i]);
      enemy[i]->add("force",-50);
      COMBAT_D->report_status(enemy[i]);
    }
  }
  me->add_temp("supertengin/thunder",1);
  call_out("again_thunder", 2, me);
  return 1;
}
