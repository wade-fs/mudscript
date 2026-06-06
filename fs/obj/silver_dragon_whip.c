//silver_dragon_whip.c
#include <ansi.h>
#include <weapon.h>
inherit WHIP;
object me=this_player();
int funp=me->query("functions/snake-steps/level");
int spe1=me->query("spells/hardshell/level");
int spe2=me->query("spells/manabody/level");
int spell=(spe1+spe2)/2;
int spi=me->query_spi();
int con=me->query_con();
int str=me->query_str();
int kar=me->query_kar();
int volume=(spi+con+str+kar)*spell;
void create()
{
        set_name(HIW + "銀龍幻星鏈" + NOR,({"silver dragon whip","whip"}));
        set_weight(4200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","條");
                set("value",700000);
                set("no_put",1);
                set("no_drop",1);
                set("no_get",1);
                set("no_sell",1);
                set("no_auc",1);
//                set("no_give",1);
                set("no_steal",1);
                set("sharp",10);
                set("material","crimsonsteel");

                set("long",
HIW + "閃爍著耀眼銀光的魔鞭，是傳說中八岐大蛇後裔所修道而成的肉身。
請以dream、star、defense使用相關特技\n" + NOR);
        }
        init_whip(70);
        set("weapon_prop/dodge", 10);
        set("weapon_prop/parry", 10);
        set("weapon_prop/whip", 15);
        set("weapon_prop/force", 10);
        setup();
}
void init()
{
  add_action("do_wield","wield");
  add_action("do_perform","dream");          //for 魔教  busy + 放毒
  add_action("do_perform2","star");          //for 天道  打精氣神 or 封per、exert
  add_action("do_perform3","defense");   //for both  提升防禦力  與上兩者相斥
  add_action("do_perform4","release");       //for both  解除防禦力
}
int do_wield(string str)
{
    ::wield();
    if( query("equipped") )
    {
    if(str=="whip" || str=="all")
    {
     if(me->query("family/family_name")!="冥蠱魔教" && me->query("family/family_name")!="天道派") 
     {
          message_vision("$N手拿著銀龍幻星鏈甩了幾下，感覺只是一條很普通的鞭子。\n",me);
     }else{
          set_heart_beat(1);
          message_vision(HIY + "$N拿起" + HIW + "銀龍幻星鏈" + HIY + "，千年龍的魔力緩緩注入心中，$N若有所思。\n" + NOR,me);
          } 
    }
    }
}
void heart_beat()
{
    int per=me->query_per();
    if(me->query("family/family_name")=="冥蠱魔教" || me->query("family/family_name")=="天道派")
    {
    if(query("equipped") && me->is_busy() && random(60) > kar+spi+per) 
     {
     me->receive_damage("kee",100);
     me->delete_busy();
     message_vision(HIW + "
銀龍的靈氣籠罩，以千年修行源源不絕的灌注仙氣於$N體內!!
$N內勁暴綻，強行掙脫了束縛，卻也因用力過度而嘔了口血。\n" + NOR,me);
COMBAT_D->report_status(me);
     }
    }
    return;
}
int do_perform()
{
if( me->query_temp("chain-array") && userp(me) ) return notify_fail("幻星鍊的魔力不足以同時支配兩大絕學。\n");
else{
        object *target,room;
        int i,j,k,l,fun,funs,busy;
        room= environment(me);
        target = me->query_enemy(room);
        i=sizeof(target);
        funs=me->query("functions/suck/level");
        fun=(funs+funp)/2;
        busy=fun/(120-fun);

if(me->query("family/family_name")!="冥蠱魔教")
                 return notify_fail("這項武功只有冥蠱魔教的教眾能夠融會運用!!\n");
if(!me->is_fighting()) return notify_fail("只有在戰鬥中才能使用\n");
if(target[j]->is_busy()) return notify_fail("就算你是魔教徒，也不能趁人之危吧，先讓他喘口氣啦!!\n");
          message_vision(HIC + "\n$N仰天長嘯 ：

  " + HIM + "＊＊＊＊＊＊＊＊＊ " + BLINK+HIR + "夢  幻  鬥  舞 " + NOR + "" + HIM + "＊＊＊＊＊＊＊＊＊

  " + HIW + "夢幻般的九天靈影步法，飛快的將戰場圍成一個小圈子，
  " + HIW + "同時幻星鏈亦朝$n周身大穴招呼，一時間空氣中銀光
  " + HIW + "閃耀，刺眼氣芒有如水銀瀉地，卻又似雲山中的銀龍盤旋
  " + HIW + "交錯，使人感覺彷彿置身夢境...... \n" + NOR,me,target[j]);
if(70>random(100)) {
        for(j=0;j<i;j++)
        {
        	message_vision(
  HIY + "$n完全被眼前奇景迷惑住，警戒鬆懈、毫不設防。\n" + NOR,me,target[j]);
            if(!target[j]) continue;
            if( target[j]->is_character() && !target[j]->is_corpse() && living(target[j]))
            {
            target[j]->start_busy(busy+1);
            me->start_busy(1);
COMBAT_D->report_status(target[j]);
            }
if (30>random(100))
               {
message_vision(HIR + "
  一股腥紅鮮豔的氣息由鞭子裡散發出來，
  慢慢在空氣中擴散，$n冷不防吸了一大口...
" + NOR,me,target[j]);
                target[j]->apply_condition("evil_poison",random(10)+5);
                target[j]->apply_condition("evil_pill01",random(10)+5);
                target[j]->apply_condition("evil_pill02",random(10)+5);
COMBAT_D->report_status(target[j]);
               }
        }
} else {
        room= environment(me);
        target = me->query_enemy(room);
        i=sizeof(target);
        message_vision("
  " + GRN + "$n識破其中的奧秘，絲毫不為美麗的幻影所動。
       \n" + NOR,me,target[j]);
       }
}
  return 1;
}

int do_perform2()
{
if( me->query_temp("chain-array") && userp(me) ) return notify_fail("幻星鍊的魔力不足以同時支配兩大絕學。\n");
else{
        object *target,room;
        int i,j,k,l,kdamage,sdamage,gdamage,mkee,sen,msen,gin,mgin;
        room= environment(me);
        target = me->query_enemy(room);
        i=sizeof(target);

if(me->query("family/family_name")!="天道派")
                 return notify_fail("這項絕技只有道行高深的的修行者能夠自由操控!!\n");
if(!me->is_fighting()) return notify_fail("這是在戰鬥中才能使用的喔\n");
if(target[j]->is_busy()) return notify_fail("修道之士不能趁人之危，先讓對方喘口氣吧\n");
if(70>random(100)) {
        sen=me->query("sen");
        gin=me->query("gin");
        mkee=me->query("max_kee");
        msen=me->query("max_sen");
        mgin=me->query("max_gin");

       if( userp(target[j]))
             {
              sdamage=sen/5;
              kdamage=mkee/4;
              gdamage=gin/5;
             }
         else 
             {
              kdamage=mkee/2;
              sdamage=msen*1/3;
              gdamage=mgin*1/3;
             }
          message_vision(HIW + "
  突然間，穹蒼黯淡，千年龍的靈氣引導$N飛快舞動銀鞭，
  在身前形成一道散發著微弱光芒的水晶牆...

                 " + HIM + "＊ " + HIB + "終 " + HIM + "＊ " + HIB + "極 " + HIM + "＊ " + HIB + "星 " + HIM + "＊ " + HIB + "光 " + HIM + "＊ " + HIM + "＊

                            " + HIY + "水晶牆上的點點亮光幕然暴長，飛升化為星辰，
                            接著又降下數道浩然星光，將$n的身影逐漸吞噬...
       " + NOR,me,target[j]);
        for(j=0;j<i;j++)
        {
            if(!target[j]) continue;
            if( target[j]->is_character() && !target[j]->is_corpse() && living(target[j]) && 30>random(100))
            {
              message_vision(
HIC + "                     無數隕石降下，挾帶著星之力如雨點般落於$n肉身，
                            且精神更因為目睹天地劇變而驚駭莫名......
                     \n" + NOR,me,target[j]);
              target[j]->receive_wound("gin",gdamage);
              target[j]->receive_wound("sen",sdamage);
              target[j]->receive_damage("kee",kdamage);
              target[j]->start_busy(random(3)+1);
              COMBAT_D->report_status(target[j]);
            }
            else{
              message_vision(
HIR + "                     光芒籠罩的中心點，$n三魂七魄直接遭受星辰靈氣衝擊，
                            內息不知不覺間受到牽引，頓時一陣紊亂......
                     \n" + NOR,me,target[j]);
                 target[j]->apply_condition("no_power_e",random(10)+5);
                 target[j]->apply_condition("no_power_f",random(10)+5);
                 target[j]->apply_condition("tsunami",random(10)+5);
                 target[j]->start_busy(random(3)+1);
                }
           me->start_busy(1);
        }
} else {
        room= environment(me);
        target = me->query_enemy(room);
        i=sizeof(target);
        message_vision(HIW + "
  突然間，穹蒼黯淡，千年龍的靈氣引導$N飛快舞動銀鞭，
  在身前形成一道散發著微弱光芒的水晶牆...

                 " + HIM + "＊ " + HIB + "終 " + HIM + "＊ " + HIB + "極 " + HIM + "＊ " + HIB + "星 " + HIM + "＊ " + HIB + "光 " + HIM + "＊

                            " + HIY + "水晶牆上的點點亮光幕然暴長，飛升化為星辰，
                            接著又降下數道浩然星光，將$n的身影逐漸吞噬...
                            " + GRN + "$n狼狽地左閃右避，勉強逃過此劫。
       \n" + NOR,me,target[j]);
       }
}
  return 1;
}
int do_perform3()
{
  if(me->query("family/family_name")!="冥蠱魔教" && me->query("family/family_name")!="天道派")
    {	
      return notify_fail("嗯!?\n");
    }
else{
  if(me->query("family/family_name")=="冥蠱魔教")
    {
     if( me->query_temp("chain-array") ) return notify_fail("你已經在用嘍\n");
     if(!query("equipped")) return notify_fail("同志，麻煩先裝備上手再用吧!!\n");
       else{
           message_vision(HIY+HBBLU + "
龍的力量" + NOR + "" + HIM + "灌注，$N不斷地將《" + BLK+HBBLU + "靈蛇幻影" + NOR + "" + HIM + "》谷催在極限邊緣，
" + HIW + "__________    ──────────____________      ___________
        ____________   ________  ───────────" + HIY + "身軀逐漸發光..." + HIW + "
    ───────────    ____________   ___________ ───────────
 ________  ──────── " + HIB+BLINK + "靈   " + HIG + "蛇   " + HIW + "鬥   " + HIR + "舞 " + NOR + "" + HIW + " ─────      
     ───────________________   ───────── __________
──────────  _________________     ________ ────────
" + HIW + " ─── " + HIR + "在旁人眼裡看來，眼前只見一道道亮得令人無法逼視的閃光，" + HIW + "________
" + HIW + "  ________    " + HIY + "$N的肉身則有如從空氣中蒸發了一樣。" + HIW + "──────
    ──────────            ____________________        ___________\n" + NOR,me);
           (int)me->add_temp("apply/dodge",funp);
           (int)me->add_temp("apply/move",funp);
           (int)me->add_temp("apply/parry",funp);
         }
    }
  if(me->query("family/family_name")=="天道派")
    {
     if( me->query_temp("chain-array") ) return notify_fail("你已經在用嘍\n");
     if(!query("equipped")) return notify_fail("道長，拜託先裝備上手再用吧!!\n");
     else{
           message_vision(HIC + "
    星之力" + HIW + "引導$N高速舞動" + HIY+BRED + "幻星鍊" + NOR + "" + HIW + "，使$N參透失傳的" + HBMAG+HIC + "古代密咒" + NOR + "
    
" + HIW + "         ☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★
" + YEL + "        ☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆
" + HIW + "       ★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆
" + HIG + "      ★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★
" + HIW + "     ★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆
" + HIC + "    ★☆★☆★☆★☆★" + HIW+BLINK + " 極  光  障  璧 " + NOR + "" + HIC + "☆★☆★☆★☆★
" + HIM + "     ★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆
" + RED + "      ★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★
" + HIW + "       ☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★
" + CYN + "        ★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★
" + HIW + "         ☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★

" + HIY + "            七彩水晶牆" + HIW + "峙如淵嶽  將$N層層包圍       
" + HIC + "  其所散發出的驚人凍氣   彷彿要將一切試圖穿透它的物體冰結。
           \n" + NOR,me);
        me->add("max_kee",volume);
        me->add("eff_kee",volume);
        me->add("kee",volume);
         }
    }
    me->start_busy(3);
    me->set_temp("chain-array",1);
        }
  return 1;
}
int do_perform4()
{
   if(me->query("family/family_name")!="冥蠱魔教" && me->query("family/family_name")!="天道派")
   {
     return notify_fail("......\n");
   }else{
    if(me->query("family/family_name")=="冥蠱魔教")
    {
    	(int)me->add_temp("apply/dodge",-funp);
    	(int)me->add_temp("apply/move",-funp);
    	(int)me->add_temp("apply/parry",-funp);
    }
    if(me->query("family/family_name")=="天道派")
    {
    	me->add("max_kee",-volume);
        me->set("eff_kee",me->query("max_kee"));
    }
   message_vision(HIG + "$N收斂" + HIW + "銀龍幻星鍊" + HIG + "魔力，週遭的異象逐漸回歸自然。\n" + NOR,me);
   me->delete_temp("chain-array",1);
   }
  return 1;
}
