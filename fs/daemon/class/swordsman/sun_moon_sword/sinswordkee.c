// 仙劍貳轉perform 因為加上busy 因此無法連發
#include <combat.h>
#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int perform(object me, object target)
{
 object *enemy,ob,room,obj;
 mixed all;
 int damage,i,j,k,l,m,level;
 int limit=me->query("quests/fucheck");
 enemy=me->query_enemy();
 room = environment(me);
 all = all_inventory(room);
 i=sizeof(enemy);
 j=sizeof(enemy);
 k=sizeof(enemy);
 l=sizeof(enemy);
 m=sizeof(enemy);
 if(!me->query("quests/sinswordkee"))
  return notify_fail(HIY + "你未經過武禪修練...怎麼可能使用武禪絕學呢?\n" + NOR);
 if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type") != "sword")
  return notify_fail(HIY + "只有在使用劍術的時候你才能運用武禪的威力。\n" + NOR);
 if (me->query_temp("no_power_sword",1))
  return notify_fail (HIY + "你的身體狀況未平復, 無法使用涅盤殺禪劍。\n" + NOR);
 if(!me->is_fighting())
  return notify_fail(HIY + "『●武*********禪●』只能在戰鬥中使用。\n" + NOR);
 if ((string)me->query ("family/family_name") != "仙劍派")
  return notify_fail ("你並非仙劍弟子, 焉可使用。\n");
 if(me->query("force") < 1500)
  return notify_fail("你的內力不夠發出武禪的威力。\n");
 damage = 8*me->query_function("sinswordkee")+5*me->query_skill("sun_moon_sword",1);
 level=me->query("functions/sinswordkee/level");
 if(me->query("functions/sinswordkee/level")==0) me->set("quests/fucheck",(limit+1));
 me->set_temp("no_power_sword",1);
 me->apply_condition("no_power_sword",0);
// 0 為過一次condition 的意思..經過測試戰鬥中約為15-20sec
 me->add("force",-300+3*random(level));
 me->recieve_damage("kee",-450);
 me->recieve_damage("gin",-300);
 me->recieve_damage("sen",-300);

 if (me->query("quests/sinswordkee")==1)
  {
   message_vision(HIY + "\n
              $N大喝一聲："+HIC + "『"+HIW + "小賊！！看我武禪絕招--涅盤轉生"+HIC + "』
            "+HIY + "$N隨著本身修練的佛道之氣使出"+HIG + "涅盤殺禪劍之涅盤轉生
            "+HIY + "繞著所有敵人不停出劍對攻，走了一個大圈便停了下來\n
    "+HIC + "瞬間$N將配劍狂轟地上，先前走過處已用腳力破爆圓圈，立時升出勁力壁牆\n        $N再轉動自身發出無數劍氣，這一招便是師承武禪之"+HIG + "*涅盤轉生*"+HIB + "。\n" + NOR,me);
   while(i--)
   {
if((me->query("combat_exp")/20000+me->query_skill("sun_moon_sword",1)) > (random(enemy[i]->query("combat_exp")/100000)+random(enemy[i]->query_skill("dodge",1))))
     {
      enemy[i]->receive_wound("kee",damage+100);
      enemy[i]->start_busy(1);
      message_vision(HIR + "$N人動勁圈也動，$n欲以力破出，但竟遭強猛內力割傷﹔轟其真身，旋轉的氣勁又如鋒銳利刃，*涅盤轉生*更是不斷收縮圓圈，$n身軀遭無數劍氣摧殘，頓時臥倒在地！\n" + NOR,me,enemy[i]);
      COMBAT_D->report_status(enemy[i]);
     }
    else
     {
      message_vision(HIR + "$n見到這至極一招早已嚇呆，身體被『●涅盤轉生●』圓形氣勁束縛！\n" + NOR,enemy[i]);
      message_vision(YEL + "$n憑著本身的功\力硬擋這撼天一招，但不免也為『●涅盤轉生●』強烈勁氣所傷！！！\n" + NOR,enemy[i]);
      enemy[i]->receive_wound("kee",(damage+100)/2);
     }
    }
  }
  else if(me->query("quests/sinswordkee")==2)
   {
   message_vision(HIB + "\n
                    $N大喝一聲"+HIC + "『"+HIW + "小賊！！看我武禪絕招--雷禪震"+HIC + "』
                    "+HIB + "$N眼中閃爍著奇異的光芒頓時天空烏雲密佈..
                "+HIG + "涅盤殺禪劍之*雷禪震*"+HIB + "，催動九天神雷，只見此一地區籠罩
    在無數雷舌之下，仔細一瞧....光舌竟聚集於$N劍上!!，蓄勢待發，猶如雷神再現
                       這一招便是師承武禪之"+HIG + "*雷禪震*"+HIB + "。\n\n" + NOR,me);
   while(i--)
   {
if((me->query("combat_exp")/20000+me->query_skill("sun_moon_sword",1)) > (random(enemy[i]->query("combat_exp")/100000)+random(enemy[i]->query_skill("dodge",1))))
{
      enemy[i]->receive_wound("kee",damage+250);
      enemy[i]->start_busy(1);
      enemy[i]->apply_condition("hellthunder",5);
      message_vision(HIR + "面對眼前駭人景象$n已嚇的魂不附體，$n本能性的退後數步，但九天神雷畢竟不是一般人所能閃躲，$n身軀遭無情雷殛，身上散發出無奈的焦味！！！\n" + NOR,me,enemy[i]);
      COMBAT_D->report_status(enemy[i]);
     }
    else
     {
      message_vision(HIR + "$n見到這狂霸雷擊早已嚇呆，身體被『●雷禪震●』神雷所縛！！！\n" + NOR,me,enemy[i]);
      message_vision(YEL + "$n憑著本能反應，瞬間閃過狂霸神雷之追擊，但不免也為"+HIG + "『●雷禪震●』"+YEL + "雷殛所傷！！！\n" + NOR,me,enemy[i]);
      enemy[i]->receive_wound("kee",(damage+250)/2);
     }
    }
  }
  else if(me->query("quests/sinswordkee")==3)
   {
   message_vision(HIG + "\n
      $N運起師承武禪之五劫真氣 "+HIM + "風-火-水-地-天 " + HIG + "運起身上無極劍氣\n
      配合$N身上霸絕之殺意牽動"+HIW + "◎"+HIY + "涅盤殺禪劍"+HIW + "◎"+HIG + "奧義"+HIR + "★"+HIC + "涅盤劫"+HIR + "★"+HIG + "
    挾帶五種不同勁力，牽動天地五大精英形成迦邏五芒陣包圍在場的眾人！\n\n" + NOR,me);
//解迷完成度100%,加上練滿 150 及轉換fu 內容..
//加上new pe 限制..so 威力加強成一對多..busy 數增加
//攻擊殺整個房間的人..如過運用在解quest 的npc 如sa ..則取消對sa 的攻擊
if(level==150)
  {
   message_vision(HIM + "$N運起渾身劍氣，發動全身劍氣，配合涅盤劫氣勁由身上竄出五道不同顏色的劍氣！\n" + NOR,me);
   message_vision(HIC + "瞬間五大神英之形，爆然而出，"+HBCYN + "巽痕"+NOR + ""+HBRED + "妖焰"+NOR + ""+HBBLU + "伏濤"+NOR + ""+HBYEL + "壙埌"+NOR + ""+HBWHT + "靈曜"+NOR + ""+HIC + "五大精英劍靈在半空中盤旋不定\n\n" + NOR,me);
   message_vision(HIW + "    $N大喊：『"+HIR + "涅 盤 日 月 開 天 地 ， 殺 禪 無 量 破 乾 坤"+HIW + "』"+HIY + "！\n\n" + NOR,me);
   message_vision(HIY + "隨著$N的呼喚，眾神英頓時粉碎，換化成無數劍刃，由遠至近，由大至小，無窮無盡\n整個空間裡所有人見到目前的景象，難掩心中驚駭之情，雖想逃跑，但雙腳卻是不聽使喚！\n" + NOR,me);
   for( i = 0 ; i < sizeof(all) ; i++)
  {
   obj = all[i];
   if (obj->is_character() && !obj->is_corpse() && living(obj)&& obj->query("id")!=me->query("id"))
     {
      tell_object(obj,HIR + "\n你避無可避，一個不留神，數百道劍雨已貫穿你的身體！\n" + NOR);
      obj->receive_wound("kee",damage+1000);
      obj->start_busy(3);
      obj->apply_condition("tsunami",5);
      me->start_busy(1);
      COMBAT_D->report_status(obj, 1);

     }
   }
  }
 else
  {
   message_vision(HIC + "$N牽引風劫之氣牽動"+HBCYN + "風元精英--巽痕"+NOR + ""+HIC + "，捲起狂風之刃，大氣之狂風精氣瞬間活化，帶動無數氣爆，引動涅盤風劫！！\n\n" + NOR ,me);
   while(i--)
    {
     if((me->query("combat_exp")/30000+me->query_skill("sun_moon_sword",1)) > (random(enemy[i]->query("combat_exp")/100000)+random(enemy[i]->query_skill("dodge",1))))
      {
       enemy[i]->receive_wound("kee",damage/7);
      }
     else
      {
       enemy[i]->receive_wound("kee",damage/10);
      }
     }
   message_vision(HIR + "$N牽引火劫之氣牽動"+HBRED + "火元精英--妖焰"+NOR + ""+HIR + "，引爆烈火之焰，空氣中的烈火元素漸漸爆出耀眼火光，隨後一聲巨響，浩瀚火海無窮無盡引爆涅盤火劫！！\n\n" + NOR ,me);
   while(j--)
   {
    if((me->query("combat_exp")/30000+me->query_skill("sun_moon_sword",1)) > (random(enemy[j]->query("combat_exp")/100000)+random(enemy[j]->query_skill("dodge",1))))
     {
      enemy[j]->receive_wound("kee",damage/7);
     }
    else
     {
      enemy[j]->receive_wound("kee",damage/10);
     }
   }
   message_vision(HIB + "$N牽引水劫之氣牽動"+HBBLU + "水元精英--伏濤"+NOR + ""+HIB + "，帶動浩瀚之浪，散佈空氣中的泓水元素牽引大海之浪，帶動無邊無際之狂暴海嘯，掀起涅盤水劫！！\n\n" + NOR ,me);
  while(k--)
   {
   if((me->query("combat_exp")/30000+me->query_skill("sun_moon_sword",1)) > (random(enemy[k]->query("combat_exp")/100000)+random(enemy[k]->query_skill("dodge",1))))
     {
      enemy[k]->receive_wound("kee",damage/7);
     }
    else
     {
      enemy[k]->receive_wound("kee",damage/10);
     }
    }
message_vision(HIY + "$N牽引地劫之氣牽動"+HBYEL + "地元精英--壙埌"+NOR + ""+HIY + "，勾起大地之音，呼喚浩瀚大地元素，瞬間一聲地鳴挾帶耀眼地光，大地隨之劇烈震盪，帶動涅盤地劫！！\n\n" + NOR ,me);
   while(l--)
   {     
      if((me->query("combat_exp")/30000+me->query_skill("sun_moon_sword",1)) > (random(enemy[l]->query("combat_exp")/100000)+random(enemy[l]->query_skill("dodge",1))))
      {
      enemy[l]->receive_wound("kee",damage/7);

     }
    else
     {
      enemy[l]->receive_wound("kee",damage/10);
       }
     }
message_vision(HIW + "$N牽引天劫之氣牽動"+HBWHT + "天地精英--靈曜"+NOR + ""+HIW + "，匯集四大精英之氣，牽動天地之氣，引起五大元素產生共鳴，造成浩瀚無邊之震撼並挾帶開天闢地的狂暴氣勁，重擊陣中所有敵人！！！\n\n" + NOR ,me);
   while(m--)
   {
     if((me->query("combat_exp")/15000+me->query_skill("sun_moon_sword",1)) > (random(enemy[m]->query("combat_exp")/100000)+random(enemy[m]->query_skill("dodge",1))))
     {
      enemy[m]->receive_wound("kee",damage);
      enemy[m]->apply_condition("tsunami",5);
      enemy[m]->start_busy(2);
      message_vision(HIR + "面對眼前駭人景象$n已嚇的魂不附體，$n嚇的臉色發青，冷汗直流，但$N的攻勢仍無情的在$n身上留下一大塊恐怖的傷痕！\n" + NOR,me,enemy[m]);
      COMBAT_D->report_status(enemy[m]);
     }
    else
     {
      message_vision(HIR + "$n左閃右躲，想盡力避開這狂霸一擊，但一個分神，亦遭迦邏五芒陣吞噬！\n" + NOR,me,enemy[m]);
      enemy[m]->start_busy(1);
      enemy[m]->receive_wound("kee",damage/2);
      me->receive_wound("kee",5);
     }
    }
   }
  }
  else if(me->query("quests/sinswordkee")==4)
    {
   message_vision(HIY + "
$N頓時領悟出師成武禪涅盤殺禪劍之"+HIM + "春夢醒來恨無窮"+HIY + "佛道同心
長劍起落迅速猶如狂風暴風般急刺疾舞，連划無數夢圈，幻作無數劍圈，招招帶血，劍劍含淚\。\n" + NOR,me);
   while(i--)
   {
if((me->query("combat_exp")/20000+me->query_skill("sun_moon_sword",1)) > (random(enemy[i]->query("combat_exp")/100000)+random(enemy[i]->query_skill("dodge",1))))
{
      enemy[i]->receive_wound("kee",damage);
      enemy[i]->start_busy(1);
      message_vision(HIR + "面對此等招式，$n全身感到一種無名的愁意，竟在對陣中露出武者最忌諱的破綻
$N連人帶劍，如夢似幻在$n身上殺出陣陣血圈，$n想躲避，但為時已晚！！\n" + NOR,me,enemy[i]);
      COMBAT_D->report_status(enemy[i]);
     }
    else
     {
      message_vision(HIR + "$n意會到此招殺意，急速閃避但無數劍圈豈是說避就能避！！\n" + NOR,me,enemy[i]);
      message_vision(YEL + "$n憑著本能反應，瞬間閃過『●春夢醒來恨無窮●』之殺招，但無勁殺意卻防不勝防！！！\n" + NOR,me,enemy[i]);
      enemy[i]->receive_wound("kee",damage/2);
     }
    }
  }
  else if(me->query("quests/sinswordkee")==5)
   {
   message_vision(HIY + "\n
$N突輕禪起長劍，深吸一口真氣，右手豎起劍指，內力逼破指頭，血柱沖飛
"+HIG + "劍指竟以血在半空畫出涅盤劍符，再以雙掌轟符壓向半空長劍，揮出武禪最高境界
融會佛、道內力真元而苦修而成之絕招"+HIR + "涅盤殺禪劍之天怒人怨殺無邊"+HIG + "。\n" + NOR,me);
   while(i--)
   {
if((me->query("combat_exp")/20000+me->query_skill("sun_moon_sword",1)) > (random(enemy[i]->query("combat_exp")/100000)+random(enemy[i]->query_skill("dodge",1))))
{
      enemy[i]->receive_wound("kee",damage+500);
      enemy[i]->start_busy(1);
      message_vision(HIR + "$N狂殺之氣挾帶無比怨氣，殺的$n完全無法招架！\n" + NOR,me,enemy[i]);
      COMBAT_D->report_status(enemy[i]);
     }
    else
     {
      message_vision(HIR + "$n憑本身修為應擋這昊天一擊，但『●天怒人怨殺無邊●』無窮盡之怨氣隨殺招而至！！！\n" + NOR,me,enemy[i]);
      message_vision(YEL + "$n閃過劍招但敵不過怨氣之威，瞬間也為『●天怒人怨殺無邊●』殺意所傷！！！\n" + NOR,me,enemy[i]);
      enemy[i]->receive_wound("kee",(damage+500)/2);
     }
    }
  }
  else if(me->query("quests/sinswordkee")==6)
   {
   message_vision(HIY + "
$N大喝一聲『小賊！！看我武禪絕招--迦邏神魔破』，$N眼中閃爍著奇異的光芒\n
頓時天空一陣黑暗.."+HIC + "涅盤殺禪劍之*迦邏神魔破*"+HIY + "，帶動九天神魔氣息，頓時$N劍上冒出\n
無數神魔，仔細一瞧..神魔竟漸漸衝出劍中!!形成神人魔三亟滅元陣，直擊陣中所有敵人\n" + NOR,me);

   while(i--)
   {
if((me->query("combat_exp")/20000+me->query_skill("sun_moon_sword",1)) > (random(enemy[i]->query("combat_exp")/100000)+random(enemy[i]->query_skill("dodge",1))))
{
      enemy[i]->receive_wound("kee",damage+300);
      enemy[i]->start_busy(1);
      message_vision(HIR + "面對眼前駭人景象$n已嚇的魂不附體，$n本能性的退後數步，但神魔無處不在，$n身軀慘遭屠戮，身上爆出無數血花！！！\n" + NOR,me,enemy[i]);
      COMBAT_D->report_status(enemy[i]);
     }
    else
     {
      message_vision(HIR + "$n利用神魔正邪兩極之間隙，頃全力閃躲這避殺一擊！！\n" + NOR,me,enemy[i]);
      message_vision(YEL + "$n閃過神魔追擊後，$N乘隙而來，$n沒料到這招，竟被殺出一道血芒！！！\n" + NOR,me,enemy[i]);
      enemy[i]->receive_wound("kee",(damage+300)/2);
     }
    }
  }
return 1;
}
void remove_effect(object me, int skill)
{
   if (me->query("quests/fucheck")==1)
   {
   if(skill >= 150) me->set("functions/sinswordkee/level",150);
   function_improved("sinswordkee",random(me->query_skill("sun_moon_sword",1)*4.5));
   }
   else if (me->query("quests/fucheck")==2)
   {
     if(skill >= 110) me->set("functions/sinswordkee/level",110);
   function_improved("sinswordkee",random(me->query_skill("sun_moon_sword",1)*4));
   }
   else if (me->query("quests/fucheck")>=3)
   {
   if(skill >= 70) me->set("functions/sinswordkee/level",70);
   function_improved("sinswordkee",random(me->query_skill("sun_moon_sword",1)*3.5));
   }

}
