//force.c
//禪定 by blazakira
//不設上限 並將使少林派強力技能 用以降低上限使少林派的玩家保持長久使用禪定的指令的可能性

#include <ansi.h>
#include <localtime.h>

string * msg = ({
  YEL "$N去除妄想，保持靈台空明，做到無動於衷，任他狂風怒濤，我自巍然不動，順其自然。\n"NOR,
  YEL "$N保持一絲清醒，感覺著自己既是這局中之人卻又抽身於局外的超脫心境。\n"NOR,
  YEL "「萬緣放下，一念不生。」$N體會這種心境明悟自心，徹見本性。\n"NOR,
  YEL "$N退而以一念抵制萬念，從宗、教、律、淨、密，這五種法門中尋得「明心見性」的心境。\n"NOR,
  YEL "$N秉持著：「話從心起，心是話之頭；念從心起，心是念之頭；萬法皆從心生，心是萬法之頭。」反聞聞自性，觀自性。\n"NOR,
  YEL "$N思索：心即性，即覺，即佛，無有形相方所，了不可得，周遍法界，不出不入，無往無來，即本來現成的清淨法身佛。\n"NOR,
});

int update_condition(object me, int duration)
{
  int not_robot = 1;
  int *ttime = localtime(time());
  int qspi=me->query_spi(),qint=me->query_int(); //為了設定先天數值極限的變數

  if(me->query_temp("not_robot") > time() || 
    (ttime[LT_HOUR] > 0 && ttime[LT_HOUR] < 8 )) //非機器人的判定 及時間為八小時內
  {
    not_robot = 0;
  }
  if( duration < 1  )
  {
    return 0;
  }
  if (me->query_condition("force")) //如果已經在蹲內力就不能打坐
    return notify_fail (MAG"你正在忙著驅使體內的內息做周天循環，顧不得打坐參禪呢。\n"NOR);

  if(me->is_fighting()) { //若進入戰鬥
    me->start_busy(2); //這得有後遺症 避免玩家掛在mob前
    me->delete_temp("no_move"); //解除不能移動
    me->apply_condition("mess",(me->query_skill("magic")+me->query_skill("spells"))/20+1); //避免狀態時間為零
    message_vision(HIR"突如其來的殺意，使心魔衝破$N"HIR"心防，$N"HIR"於混亂心性下驅動全身的內息入了歧徑！\n"NOR , me);
    //為避免不夠氣(精 神)時會死亡故加入此判斷。
    if(me->query("kee")>200) me->add("kee",-200); //扣血
    COMBAT_D->report_status(me, 1);
    if(me->query("gin")>150) me->add("gin",-150); //扣精
    if(me->query("sen")>100) me->add("sen",-100); //扣神
    me->set("force",0);
    me->apply_condition("dhyana",0); //解除參禪的狀態
    return 0;
  }
  if(me->query("gin") < 300 || me->query("sen") < 300 ) //設定精或神<300的限制
  {
    message_vision(HIB"$N的精神不好，無法靜思以保持靈台空明。\n"NOR , me);
    me->apply_condition("dhyana",0);
    return 0;
  }
  if( me->query("atman") < me->query_skill("spells") ||
      me->query("mana") <  me->query_skill("magic") ||
      me->query("force") <  (me->query_skill("spells") + me->query_skill("magic")) ) //設定靈力 法力 內力的限制
  {
    message_vision(HIB"$N"HIB"的身體狀況欠佳，有導致虛弱的可能性。\n"NOR , me);
    me->apply_condition("dhyana",0);
    return 0;
  }
//參禪判斷開始
  me->apply_condition("dhyana",duration-1); //隨著時間經過 狀態持續時間減少
  if(duration < 2 ) //參禪動作結束
  {
    int magic = me->query_skill("magic")/20; //設定1/20倍
    int spells = me->query_skill("spells")/20;
    switch (random(2)) //random(2) 只包含 0,1
    {
      case 0 :
        me->improve_skill( "magic", magic + random(magic), not_robot );
        me->add("mana",-magic);
        break;
      case 1 :
        me->improve_skill( "spells", spells + random(spells), not_robot );
        me->add("atman",-spells);
        break;
      default : break;
    }
    me->add("force",-(magic+spells));
    message_vision(HIC "$N放下空明心境重拾七情六慾再度入世。\n"NOR,me); //結束訊息
  } else {//參禪中
    int magic = me->query_skill("magic")/10; //設定1/10倍
    int spells = me->query_skill("spells")/10;
    if(me->query_skill("magic",1) > 1000) magic = magic / 2; //技能超過lv1000 加倍減緩升級速度
    if(me->query_skill("spells",1) > 1000) spells = spells / 2;
    switch (random(2)) //random(2) 只包含 0,1
    {
      case 0 :
        me->improve_skill( "magic", magic + random(magic), not_robot );
        me->add("mana",-magic);
        break;
      case 1 :
        me->improve_skill( "spells", spells + random(spells), not_robot );
        me->add("atman",-spells);
        break;
      default : break;
    }
    me->add("force",-(magic+spells));
    message_vision(msg[random(sizeof(msg))] , me); //使用陣列裡的訊息

//後天數值 如使用裝備 聖靈戰甲時 有可能將spi提高到245+35 >>add(22)的可能性 >>佛法數值超乎想像的高
//故控制在可預測的範圍而限制 設定先天數值才有效 >>即限制最高add(5)的情況下
  if (me->query_spi() > 35) qspi=35;
  if (me->query_int() > 35) qint=35;
    me->add("s_kee",(qspi+qint)/14); //max_(spi+int)/14=70/14>>add(5) 最小為1
    me->add("atman",-150); //靈力
    me->add("mana",-100); //法力
//不設最大值 但是 過了正常範圍值後 增加的數值較少
//設定正常範圍：(可含後天裝備增加的素質)
    if(me->query("max_s_kee")>=(me->query_spi()+me->query_int())*5+me->query("max_atman")/20+me->query("max_mana")/20) //超過正常範圍時
    { //先天最高值為(35+35)*5=350
      if(me->query("s_kee")>me->query("max_s_kee")*7) //設定7倍之後才會增加
      {
        me->add("max_s_kee",1);
        me->set("s_kee",me->query("max_s_kee"));
        tell_object(me,HIY "你對於佛理有更深刻的體悟了！\n" NOR);
        return 1; //跳出7倍限制 並結束
      }
    } else if(me->query("s_kee")>me->query("max_s_kee")*2) //正常範圍內 設定2倍之後才會增加
    {
      me->add("max_s_kee",1);
      me->set("s_kee",me->query("max_s_kee"));
      tell_object(me,HIY "你對於佛理有更深刻的體悟了！\n" NOR); //不設return 直接使用最後的return
    }
    return 1;
  } //參禪結束
  return 1;
}
