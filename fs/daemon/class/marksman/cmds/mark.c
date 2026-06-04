//射手目標定位 by frequency
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int report=0;
int vet(object me);
int main(object me, string arg)
{
    object ob, coco,oob;
    int sk, sk2, mk, tk, mg, tg, ms, ts, amount;
    string str, name, id;
    id = me->query("id");
    sk = (int)me->query_skill("cure",1);
    sk2 = (int)me->query_skill("godcure",1);
    
    if(!me) return 1;
    if(!arg) return notify_fail("指令格式：cmd mark <id>\n");
    arg = lower_case(arg);
    ob = present(arg, environment(me));
    if(!objectp(ob)) return notify_fail("你想以誰為目標啊？\n");
    if(!ob->is_character()) return notify_fail("你只能攻擊活物好不好！\n");
    if(ob->is_corpse()) return notify_fail("你想鞭屍嗎？\n");
    if(ob->query("no_kill")) return notify_fail("他知道你想對他作啥，還是放棄吧！\n");
    if(ob->query("no_askgod")) return notify_fail("他知道你想對他作啥，還是放棄吧！\n");
    if(ob->query_temp("netdead")) return notify_fail("他離開了這個世界，因此無法幫他看診！\n");

    name = ob->query("name");
    if(me->query_temp("mark_goal"))
    {
    oob = me->query_temp("mark_goal");
    oob->delete_temp("marked",me);
    }
    me->set_temp("mark_goal",ob);
    me->set_temp("mark",1);
    ob->set_temp("marked",me);
    ob->set_temp("be_shooted",1);

        message_vision(HIR + "$N運起" + HIG + "【" + HIC + "冰心訣" + HIG + "】" + HIR + "最高功\力，" + HIG + "《" + HIC + "六月飛霜" + HIG + "》" + HIR + "！\n\n" + NOR,me, ob);
        message_vision(HIW + "只見天上降下大雪，其中數片雪花在$n身上凝聚成了一小撮清晰的記號。\n\n" + NOR,me, ob);
        if(me->query_cps() < random (50))
        ob->kill_ob(me);
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式：cmd mark <id> || 限射手使用
指令說明：
　　　　射手在長程攻擊之前，須先以這指令確認目標所在。
HELP);
        return 1;
}

