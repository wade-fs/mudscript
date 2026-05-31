// dremagic.c //cgy

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="magic"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("magic") < (int)me->query_skill("dremagic")/2 )
                return notify_fail("你的法術修為不夠﹐無法領悟更高深的夢玄法鑑。\n");
        return 1;
}

string conjure_magic_file(string magic)
{
        return CLASS_D("dancer") + "/dremagic/" + magic;
}
int conjure_magic (object me, string magic, object target)
{
	if( file_size(conjure_magic_file(magic)+".c") > 0 )
	return conjure_magic_file (magic)->conjure(me,target);
	return notify_fail("沒有這樣法術。\n");
}


int practice_skill(object me)
{       
        object bug;

        if( bug = me->query_temp("mind_bug") )
                return notify_fail("你的魂魄還沒有全部收回﹐趕快殺死你的"
                        + bug->name() + "吧﹗\n");

        if( (int)me->query("atman") < 10 )
                return notify_fail("你的靈力不夠。\n");

        if( (int)me->query("gin") < 30 )
                return notify_fail("你的精神無法集中。\n");

        me->add("atman", -10);
        me->receive_damage("gin", 30);

        write("你閉目凝神﹐神遊物外﹐開始修習茅山道術中的法術....\n");
        if( random((int)me->query("gin")) < 5 ) {
                int rnd;
                rnd = random(me->query_skill("magic", 1));
                if( rnd < 10 )  bug = new("/obj/npc/mind_bug");
                else                    bug = new("/obj/npc/mind_beast");

                write("可是你心思一亂﹐變出了一隻面目猙獰的" + bug->name() + "﹗\n");
                bug->move(environment(me));
                bug->kill_ob(me);
                me->fight(bug);
                me->set_temp("mind_bug", bug);
                bug->set("owner", me->query("id"));
                return notify_fail("你的魂魄正被" + bug->name() + "纏住﹐快把牠除掉吧﹗\n");
        }       
        else return 1;
}
