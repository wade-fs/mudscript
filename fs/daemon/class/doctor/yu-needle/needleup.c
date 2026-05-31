//極火金身
// 註：需判定使用者身上是否持有獎勵道具 by blazakira
#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
 
void remove_effect(object me, int amount);

int perform(object me, object target)
{
  int funlv,force,stabber,yu_needle;
  object weapon;
  force=me->query("max_force"); 
  yu_needle=me->query_skill("yu-needle",1);

  if( !me->query_temp("needleup") ) return 0; // 判定為使用者身上是否持有獎勵道具 or 該道具給予的temp
  if( me->query("class") != "doctor" ) return notify_fail("哎喲～生病了就該看醫生呀，既然轉換門派了就放棄這招吧XD\n");
  if( !me->query("quests/doctor_book") ) return notify_fail("你還沒有得到神農氏的承認。\n");
  if( (string)me->query_skill_mapped("stabber")!= "yu-needle" )
    return notify_fail("得使用七奇針訣才是銀針門的起源「神農氏醫源」支援效果之一。\n");

  if(!(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!="stabber" )
    return notify_fail("你得要有適合的武器才能用「神農氏醫源」裡的效果。\n");

  if (force<3000)
    return notify_fail("你的內力修為太差，使用神農氏醫源時很容易走火入魔喔！\n");
  if (me->query("force") < force/10)
    return notify_fail("你的內力不夠，不能發揮神農氏醫源的效果。\n");
  if(me->query_temp("needle_up")>0) return notify_fail("你已經在使用了。\n");

  funlv=me->query("functions/shen-nongshi_cure/level","shen-nongshi_cure");
  if( funlv >= yu_needle ) funlv = yu_needle; //取小值
  if (funlv > 100) funlv = 100; //上限100
  me->add("force",-force/10);
  if( me->query_temp("needleup") == 2) //個人book獎勵mark //當兩者都持有時 優先判斷高級獎勵
    me->set_temp("needle_up",2);
  else if( me->query_temp("needleup") == 1) //一般book獎勵mark
    me->set_temp("needle_up",1);
  else return 0;
  message_vision(""
  ""HIG"                 $N突然領悟神農氏醫源的至理，將體內的內力凝聚成單股螺旋氣勁，使出「"HIR"七奇針訣"HIW"－"HIY"秘針龍騰"HIW"－"HIG"」\n\n"NOR""
  ""HIG"                         $N將體內變異的真氣在自身奇經八脈的重要穴位上形成漩渦打轉。\n\n"NOR""
  ""HIW"                       只見$N感到源源不絕的內息如磅礡大海般流轉全身三百六十個穴位，充滿生機有如飛龍騰雲。\n\n"NOR,me);
  me->start_call_out( (: call_other, __FILE__, "remove_effect", me, funlv:), funlv+random(funlv)+10);
  if( me->is_fighting() ) me->start_busy(2);
  return 1;
}

void remove_effect(object me, int funlv)
{
  int yu_needle=me->query_skill("yu-needle",1);
  if(funlv >= 100) me->set("functions/shen-nongshi_cure/level",100);
  else if(funlv < yu_needle )
  function_improved("shen-nongshi_cure",(funlv*3+random(funlv*5)));

  me->delete_temp("needle_up");
  message_vision("$N感到在穴位中打轉的內息渙散了。\n",me);
}
