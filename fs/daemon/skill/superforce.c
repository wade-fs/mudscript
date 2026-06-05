// superforce.c
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
      
    if( me->query("max_force") < 1500 ) 
    {
        tell_object(me, "你的內力修為不夠, 最少要有一千五百點。\n");
        return 0;
    }

    if( !me->query("quests/white-crystal") ) 
    {
        tell_object(me, "你尚未得到渾天水晶, 因此無法傳授予你。\n");
        return 0;
    }

    // 前四層沒有特攻, 況且必需先解白水晶之難題, 應開放.  by hana
    if( me->query("family/master_name") == "司馬錦" || me->query("family/master_name") == "葛輝" || me->query("family/master_name") == "司徒榮" || me->query("family/master_name") == "司徒知華" || me->query("family/master_name") == "周琇虔" || me->query("family/master_name") == "秦憶詩" || me->query("family/master_name") == "葛梁青") 
    {
      if( me->query_skill("superforce",1) < 40 )
      {
          return 1;
      }
      else
      {
          tell_object(me, "[36m跟八位門主只能夠學到[渾天寶鑑]的第四層心法。[0m\n");
          return 0;
      }
    }

    if( me->query("family/master_name") == "傳功\長老" || me->query("family/master_name") == "執法長老" || me->query("family/master_name") == "戒律長老" ) 
    {
      if( me->query_skill("superforce",1) <80)
      {
          return 1;
      }
      else
      {
          tell_object(me, "[36m跟三位護教長老只能夠學到[渾天寶鑑]的第五層心法。[0m\n");
          return 0;
      }
    }

    if( me->query("family/master_name") == "駱芝芝" || me->query("family/master_name") == "陳榮鐘" || me->query("family/master_name") == "林宏昇")
    return 1;

      //如果拜玩家只能到80
      if( me->query_skill("superforce",1) < 100)
    {
        return 1;
    }
    else 
    {
        tell_object(me, "只有跟聖火教教皇或星君學習才能學上去.\n");
        return 0;
    }
}

int practice_skill(object me)
{
    return notify_fail("渾天心法只能用學的﹐或是從(exert)中獲的熟練度。\n");
}
string perform_action_file(string action)
{
    return CLASS_D("prayer")+"/superforce/"+action;
}
string exert_function_file(string func)
{
    return CLASS_D("prayer")+"/superforce/"+func;
}
string color(object me)
{
	int sk;
	sk = me->query_skill("superforce",1);
	if (sk < 31) return HIW + "白雲煙" + NOR;
	if (sk < 41) return HIM + "玫蕩霞" + NOR;
	if (sk < 51) return YEL + "土崑崙" + NOR;
	if (sk < 61) return HIC + "碧雪冰" + NOR;
	if (sk < 81) return MAG + "紫星河" + NOR;
	if (sk < 111) return WHT + "玄混沌" + NOR;
	if (sk < 151) return HIB + "靛蒼海" + NOR;
	if (sk <201 ) return HIY + "金晨曦" + NOR;
	if (sk <251 ) return HIR + "血穹蒼" + NOR;
	return HIG + "玄宇宙" + NOR;
}
