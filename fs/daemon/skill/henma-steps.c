// henma-steps.c
#include <ansi.h>
inherit SKILL;

string *dodge_msg = 
({
      
      "$n使出"MAG"「幻滅嵐影」"NOR"﹐右足輕點﹐迴身反轉﹐"HIG"『湖靜風迎漪漣生』"NOR"﹐身行一滑開\n這正是"HIG"『煙柳綠滿風飄絮  新月如鉤映江舟』"NOR"﹐無聲無息的閃避$N的狂風暴雨般的攻擊。\n",
      "$n蹈出"MAG"「幻滅嵐影」"NOR"﹐足下斜行﹐身不點地﹐"HIY"『逢按磬鐘樓宇空』"NOR"﹐騰空飛躍而起\n若如是"HIY"『越城莫作萬里客  天外共斟千杯酒』"NOR"﹐消失於迷霧中﹐使的$N完全無法下手。\n",
      "$n斜踩"MAG"「幻滅嵐影」"NOR"﹐似實似虛﹐躍空滑開﹐"HIG"『江上無波清風徐』"NOR"﹐縱向躍開來\n原正是"HIG"『霞影劃過天際雲  山嵐迭湧青山行』"NOR"﹐瞬間從$N的身旁﹐斜斜緩緩的繞了過去。\n",
      "$n反踏"MAG"「幻滅嵐影」"NOR"﹐身化數影﹐虛實難分﹐"HIG"『回拾春意暖寒湮』"NOR"﹐斜向遠遠滑去\n此吟做"HIG"『古來青山不見憂  空惟江水去悠悠』"NOR"﹐身形忽爾凌空一提﹐輕輕柔柔的飄了開去! \n",
      "$n悟出"MAG"「幻滅嵐影」"NOR"﹐足踏身起﹐翩然閃隱﹐"HIY"『行路花落雨繽紛』"NOR"﹐身形頓失蹤跡\n語吟曰"HIY"『俯仰天地浮雲子  徘恛美景空飄流』"NOR"﹐身體微微傾側﹐使$N的力道輕柔的卸了去！",

});

int valid_enable(string usage) 
{
        return (usage=="dodge")||(usage=="move");
}

string query_dodge_msg(string limb)
{
  int dodge_pow;
  object me=this_player();

  if(!me) return dodge_msg[random(sizeof(dodge_msg))];
        dodge_pow = (int)(me->query_skill("henma-steps", 1)/10);
        if ( dodge_pow <= 5)
              return dodge_msg[random(4)];
        else
              return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        if(me->query ("combat_exp") <= (me->query_skill("linpo-steps",1)*6) )
          return notify_fail("你的戰鬥經驗不足﹐無法體會幻滅嵐影中精妙身法。\n");
        return 1;
}


int practice_skill(object me)
{
        if((int)me->query("kee")<5)
                return notify_fail("你的氣不夠﹐不能練幻滅嵐影。\n");
        me->receive_wound("kee",5);
        return 1;
}

