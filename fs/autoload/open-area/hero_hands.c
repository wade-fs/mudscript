//by frequency
//改進使用者的判斷 by blazakira 2011/3/31
//增加判斷賦予npc必殺時 會抓不到target的問題 by blazakira 2011/10/12
//增加 int wear() 作為損壞時的輔助判斷 by blazakira 2011/10/16

#include <armor.h>
#include <ansi.h>
inherit EQUIP;
inherit SSERVER;

object *target,room;

void create()
{
  set_name(HIC + "英雄" + HIY + "腕輪" + NOR,({"Hero Hands","hands"}) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",HIC + "傳說中的救世之腕，唯有能捨身取義(sacrifice)的英雄才能解放此腕的真實威力(checkhero)。\n" + NOR);
    set("unit", "雙");
    set("value", 9000000);
    set("material","steel");
    set("armor_type","hands");
    set("armor_prop/armor",  10);
    set("armor_prop/parry", 10);
    set("armor_prop/force", 15);
    set("armor_prop/dodge", 10);
    set("armor_prop/attack",10);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_save",1);
    set("wear_msg",HIC + "$N" + HIC + "感受到手中的$n" + HIC + "傳入歷代英雄的偉大思想。\n" + NOR);
  }
  setup();
}

void init()
{
  add_action("do_sacrifice","sacrifice");
  add_action("do_checkhero","checkhero");
}

int wear()
{
  object me;
  int result = ::wear();
  if( query("equipped"))
  {
    me=environment();
    if( me && me->query("hero_break") >= 1500 )
    {
//      me->delete("hero_break");
//      message_vision( HIR + "然而"+present("Hero Hands",me)->name()+HIR + "之英魂卻已經耗盡後隨之崩解了。\n" + NOR,me);
//      destruct(present("Hero Hands",me)); //在此處刪除會中斷死亡時的替身判斷 所以改用啟動心跳來刪除 by blazakira
      set_heart_beat(1);
    }
  }
  return result;
}

int do_sacrifice()
{
  if(!query("equipped")) return notify_fail("沒裝備起來不能用喔!!");
  set_heart_beat(1);
  message_vision(HIB + "$N聚氣凝神，準備隨時發動全力一擊\n" + NOR,environment(this_object()));
  return 1;
}

int do_checkhero()
{
  object ob,me;
  int a,b;
  string str;

  ob = this_object();
  me=environment(ob);

  a = me->query("hero_break");
  if ( a > 1500 )
    a = 1500;

  switch(a)
  {
    case 0..99:
      str =HIW + "英魂能量：" + HIC + "■■■■■■■■■■■■■■■\n" + NOR;
      break;
    case 100..199:
      str =HIW + "英魂能量：" + HIC + "■■■■■■■■■■■■■■□\n" + NOR;
      break;
    case 200..299:
      str =HIW + "英魂能量：" + HIC + "■■■■■■■■■■■■■□□\n" + NOR;
      break;
    case 300..399:
      str =HIW + "英魂能量：" + HIC + "■■■■■■■■■■■■□□□\n" + NOR;
      break;
    case 400..499:
      str =HIW + "英魂能量：" + HIC + "■■■■■■■■■■■□□□□\n" + NOR;
      break;
    case 500..599:
      str =HIW + "英魂能量：" + HIC + "■■■■■■■■■■□□□□□\n" + NOR;
      break;
    case 600..699:
      str =HIW + "英魂能量：" + HIC + "■■■■■■■■■□□□□□□\n" + NOR;
      break;
    case 700..799:
      str =HIW + "英魂能量：" + HIC + "■■■■■■■■□□□□□□□\n" + NOR;
      break;
    case 800..899:
      str =HIW + "英魂能量：" + HIC + "■■■■■■■□□□□□□□□\n" + NOR;
      break;
    case 900..999:
      str =HIW + "英魂能量：" + HIC + "■■■■■■□□□□□□□□□\n" + NOR;
      break;
    case 1000..1099:
      str =HIW + "英魂能量：" + HIC + "■■■■■□□□□□□□□□□\n" + NOR;
      break;
    case 1100..1199:
      str =HIW + "英魂能量：" + HIC + "■■■■□□□□□□□□□□□\n" + NOR;
      break;
    case 1200..1299:
      str =HIW + "英魂能量：" + HIC + "■■■□□□□□□□□□□□□\n" + NOR;
      break;
    case 1300..1399:
      str =HIW + "英魂能量：" + HIC + "■■□□□□□□□□□□□□□\n" + NOR;
      break;
    case 1400..1499:
      str =HIW + "英魂能量：" + HIC + "■□□□□□□□□□□□□□□\n" + NOR;
      break;
    case 1500:
      str =HIW + "英魂能量：" + HIC + "□□□□□□□□□□□□□□□\n" + NOR;
      break;
  }
  message_vision("$N持有"+query("name")+"的"+str,me);
  if( me && a >= 1500 )
  {
    me->delete("hero_break");
    message_vision( HIR + "然而"+present("Hero Hands",me)->name()+HIR + "之英魂卻已經耗盡後隨之崩解了。\n" + NOR,me);
    destruct(present("Hero Hands",me));
  }
  return 1;
}

void heart_beat()
{
  object hb,ob,me;
  int i,j,aa,br;
  ob = this_object();
  me=environment(ob);

  if( !ob ||!me || !objectp(me) || !query("equipped") )
  {
    set_heart_beat(0);
    return;
  }
  br = me->query("hero_break");
  if( me && br > 1500 )
  {
    me->delete("hero_break");
    message_vision( HIR + "然而"+present("Hero Hands",me)->name()+HIR + "之英魂卻已經耗盡後隨之崩解了。\n" + NOR,me);
    destruct(present("Hero Hands",me));
    return;
  }
  if( (me->query("kee") < (me->query("max_kee"))/10) || (me->query("gin") < (me->query("max_gin"))/10) || (me->query("sen") < (me->query("max_sen"))/10) )
    if( me->is_fighting() )
    {
      room = environment(me);
      target = me->query_enemy(room);
      i = sizeof(target);
      aa = random(3);

      if(aa == 0)
      {
        message_vision(HIW + "
            $N自殘己身祭天，感動歷代英魂由" + HIC + "英雄" + HIY + "腕輪" + HIW + "中一一飛出，抓著敵人的魂魄
            飛上天空，同時降下一道神聖天火...

            " + HIR + "無 極 天 道

            " + CYN + "只見神聖的天火將戰場完全掩蓋\住...\n" + NOR,me);
        if(!me->query_temp("pk_fight"))
        {
          for(j=0;j<i;j++)
          {
            message_vision(HIM + "$n慘遭天火焚身，瞬間五內焦爛，氣血蒸發。\n" + NOR,me,target[j]);
            target[j]->receive_damage("sen",1,me);
            target[j]->set("eff_gin",-10000);   //因為發現只寫->die有的mob不會死
            target[j]->set("gin",-10000);       //所以加了這兩行確保任何mob必死

            if( !br )
            {
              me->set("hero_break",1);
              me->add("hero_break",(target[j]->query("combat_exp")/1000000));
            } else {
              me->add("hero_break",(int)target[j]->query("combat_exp")/1000000);
            }
            if( me && br > 1500 )
            {
//              me->delete("hero_break"); //刪除判斷往前移 by blazakira
              message_vision( present("Hero Hands",me)->name()+HIR + "之英魂隨著$n焚身過後，英魂耗盡後隨之崩解了。\n" + NOR,me,target[j]);
//              destruct(present("Hero Hands",me));
            }
            if(!target[j]) continue;
            else target[j]->unconcious();
            if(!target[j]) continue; //target掛掉 所以無法使用下列target[j]->die()參數? 測試之(whatup提議此判斷) by blazakira 2011/4/7
            target[j]->die();
          }
          COMBAT_D->report_status(me);
          me->unconcious(); //原意是要讓ppl跟敵人同歸於盡，但發現在pkla時會死真身，所以改為如此

          me->set("eff_gin",-100);
          me->set("gin",-100);
          me->set("eff_kee",-100);
          me->set("kee",-100);
          me->set("eff_sen",-100);
          me->set("sen",-100);
          set_heart_beat(0);
        }
        else
        {
          for(j=0;j<i;j++)
          {
            message_vision(HIM + "$n慘遭天火焚身，瞬間五內焦爛，氣血蒸發。\n" + NOR,me,target[j]);
            target[j]->receive_damage("kee",1,me);
            target[j]->unconcious();
          }
          me->unconcious();
        }
      }
      if(aa == 1)
      {
        me->set("kee",me->query("max_kee"));
        me->set("eff_kee",me->query("max_kee"));
        me->set("gin",me->query("max_gin"));
        me->set("eff_gin",me->query("max_gin"));
        me->set("sen",me->query("max_sen"));
        me->set("eff_sen",me->query("max_sen"));
        message_vision(HIC + "英雄" + HIY + "腕輪" + HIW + "上的英魂以神聖靈力，將$N" + HIW + "身上的傷勢完全治癒。\n" + NOR,me);

        if( !br )
        {
          me->set("hero_break",1);
          me->add("hero_break",(target[j]->query("combat_exp")/2000000));
        } else {
          me->add("hero_break",(int)target[j]->query("combat_exp")/2000000);
        }
        if( me && br > 1500 )
        {
          me->delete("hero_break");
          message_vision( present("Hero Hands",me)->name()+HIR + "之英魂隨著$n焚身過後，英魂耗盡後隨之崩解了。\n" + NOR,me,target[j]);
          destruct(present("Hero Hands",me));
        }
        COMBAT_D->report_status(me);
        set_heart_beat(0);
        //ppl狀態全回復
        //考慮發展為除本身以外的同房間ppl全回復
      }
      if(aa == 2)
      {
        int gin,kee,sen,mgin,mkee,msen,kk,exp,force,atman,mana;
        gin = me->query("gin");
        kee = me->query("kee");
        sen = me->query("sen");
        mgin = me->query("max_gin");
        mkee = me->query("max_kee");
        msen = me->query("max_sen");
        exp = (me->query("combat_exp"))/1000000;
        force = (me->query("max_force")) - (me->query("force"));
        atman = (me->query("max_atman")) - (me->query("atman"));
        mana = (me->query("max_mana")) - (me->query("mana"));
        if(force < 0) force = 0;
        if(atman < 0) atman = 0;
        if(mana < 0) mana = 0; //寫錯 修正之 by blazakira
        if(exp < 1) exp = 1;
        kk = exp*((mkee-kee) + (mgin-gin) + (msen-sen) + force + atman + mana);
        if(kk < 1) kk = 1;
        message_vision(HIW + "$N的救世之心感動了" + HIC + "英雄" + HIY + "腕輪" + HIW + "裡的歷代英魂，
            引導$N將全身剩餘生命力集中，使出最後一擊。\n" + NOR,me);
        for(j=0;j<i;j++)
        {
          if( !br )
          {
            me->set("hero_break",1);
            me->add("hero_break",(target[j]->query("combat_exp")/1500000));
          } else {
            me->add("hero_break",(int)target[j]->query("combat_exp")/1500000);
          }
          if( me && br > 1500 )
          {
            me->delete("hero_break");
            message_vision( present("Hero Hands",me)->name()+HIR + "之英魂隨著$n焚身過後，英魂耗盡後隨之崩解了。\n" + NOR,me,target[j]);
            destruct(present("Hero Hands",me));
          }
          message_vision(HIB + "$n直接承受了$N的瀕死一擊，遭到難以想像的重創。\n" + NOR,me,target[j]);
          if( wizardp(me) )
          {
            tell_object(me,HIC + "攻擊數值="+kk+"點。\n" + NOR);
            tell_object(me,HIC + "exp數值="+exp+"點。\n" + NOR);
            tell_object(me,HIC + "mkee數值="+mkee+"點。\n" + NOR);
            tell_object(me,HIC + "kee數值="+kee+"點。\n" + NOR);
            tell_object(me,HIC + "mgin數值="+mgin+"點。\n" + NOR);
            tell_object(me,HIC + "gin數值="+gin+"點。\n" + NOR);
            tell_object(me,HIC + "msen數值="+msen+"點。\n" + NOR);
            tell_object(me,HIC + "sen數值="+sen+"點。\n" + NOR);
            tell_object(me,HIC + "force數值="+force+"點。\n" + NOR);
            tell_object(me,HIC + "atman數值="+atman+"點。\n" + NOR);
            tell_object(me,HIC + "mana數值="+mana+"點。\n" + NOR);
          }
          target[j]->receive_wound("kee",kk,me); //將施展攻擊者設為me 並將損壞值br的判斷往前移 by blazakira
          COMBAT_D->report_status(target[j],1);
          //敵重傷害
        }
        me->start_busy(1);
        COMBAT_D->report_status(me);
        set_heart_beat(0);
        me->unconcious();
      }
    }
  return;
}

int query_autoload()
{
  return 1;
}
