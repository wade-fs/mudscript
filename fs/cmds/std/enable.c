// enable.c
// 10/27 fix by borstquc

#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_types = ([
    "riding":"駕馭術",
        "array":        "陣法",
        "axe":          "斧法",
        "be-officer":   "政治",
        "blade":        "刀法",
        "cure":         "醫術",
        "dagger":       "匕首",
        "dodge":        "輕功\",
        "force":        "內功\",
        "hammer":       "鎚法",
        "magic":        "法術",
        "move":         "行動",
        "parry":        "招架",
        "plan":         "計謀",
        "archery" : "箭術",
         "lance":     "槍術",
        "poison":       "用毒",
        "spells":       "咒術",
        "stabber":      "刺術",
        "staff":        "杖法",
        "stick":        "棍法",
        "sword":        "劍法",
        "throwing":     "暗器",
        "unarmed":      "拳腳",
        "whip":         "鞭法",
        "secondary_blade" : "二刀流",
        "third_blade": "三刀流"
]);

int main(object me, string arg)
{
        mapping map;
        string *types, *skill, ski, map_to;
        int i, modify;
        mapping pass;

        seteuid(getuid());
        pass=F_SKILL_D->query_translate();

        if( !arg ) {
                map = me->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("你現在沒有使用任何特殊技能。\n");

                skill = keys(valid_types);
                write("以下是你目前使用中的特殊技能。\n");
                for (i=0; i<sizeof(skill); i++) {
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !me->query_skill(skill[i]) ) continue;
                        modify = me->query_temp("apply/" + skill[i]);
                        printf("  %-20s﹕ %-20s  有效等級﹕%s%3d\n" + NOR,
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "無" : to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                me->query_skill(skill[i]));
                }
                return 1;
        }

        if( arg=="?" ) {
                write("以下是可以使用特殊技能的種類﹕\n");
                skill = sort_array(keys(valid_types), (: strcmp :) );
                for(i=0; i<sizeof(skill); i++) {
                        printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
                }
                return 1;
        }
        arg = lower_case(arg);

        if( sscanf(arg, "%s %s", ski, map_to)!=2 )
                return notify_fail("指令格式﹕enable [<技能種類> <技能名稱>|none]\n");

        if( undefinedp(valid_types[ski]) )
                return notify_fail("沒有這個技能種類﹐用 enable ? 可以查看有哪些種類。\n");
        if(!wizardp(me)&&map_to!="none")
        if(!pass[map_to])       return notify_fail("這樣技能還沒開放﹐請勿使用。\n");

        if( map_to=="none" ) {
                me->map_skill(ski);
                me->reset_action();
                write("Ok.\n");
                return 1;
        } else if( map_to==ski ) {
                write("「" + to_chinese(ski) + "」是所有" + valid_types[ski] + "的基礎﹐不需要 enable。\n");
                return 1;
        }

        if( !me->query_skill(map_to, 1) )
                return notify_fail("你不會這種技能。\n");

//      if( !me->query_skill(ski, 1) )
//              return notify_fail("你連「" + to_chinese(ski) + "」都沒學會﹐更別提"
//                      + to_chinese(map_to) + "了。\n");

        if( !SKILL_D(map_to)->valid_enable(ski) )
                return notify_fail("這個技能不能當成這種用途。\n");
  if(ski=="dodge"&&me->query("class")=="blademan") {
  return notify_fail("刀客不能 enable dodge 。\n");
}
  if(ski=="move"&&me->query("class")=="blademan") { 
  return notify_fail("刀客不能 enable move 。\n"); 
}
//聖火的特攻「歸真」用，如果因歸真而失去了enable，在戰鬥中不能enable回來 by bss
        if(ski=="dodge" && me->query_temp("no_en_dodge"))
        {
                if(me->is_fighting())
                {
                        return notify_fail("歸真的奇異真氣還在你的頭腦中來回激蕩，使你無法使用"+map_to+"這項技能!!\n");
                }
                else
                {
                        me->delete_temp("no_en_dodge");
                }
        }
        if(ski=="parry" && me->query_temp("no_en_parry"))
        {
                if(me->is_fighting())
                {
                        return notify_fail("歸真的奇異真氣還在你的頭腦中來回激蕩，使你無法使用"+map_to+"這項技能!!\n");
                }
                else
                {
                        me->delete_temp("no_en_parry");
                }
        }
        me->map_skill(ski, map_to);
        me->reset_action();
        write("Ok.\n");

        if( ski=="magic" ) {
                write("你改用另一種法術系﹐靈力必須重新鍛鍊。\n");
                me->set("atman", 0);
                me->receive_damage("gin", 0);
        } else if( ski=="force" ) {
                write("你改用另一種內功\﹐內力必須重新鍛鍊。\n");
                me->set("force", 0);
                me->receive_damage("kee", 0);
        } else if( ski=="spells" ) {
                write("你改用另一種咒文系﹐法力必須重新修煉。\n");
                me->set("mana", 0);
                me->receive_damage("sen", 0);
        }

        return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : enable [<技能種類> <技能名稱> | none]
           enable ?
指令說明 :
           這個指令讓你指定所要用的技能﹐需指明技能種類和
         技能名稱。如果不加參數則會顯示出技能種類及你目前
         所使用的技能名稱﹐如果加一個 ? 會列出所有能使用
         特殊技能的技能種類。
HELP
        );
        return 1;
}
