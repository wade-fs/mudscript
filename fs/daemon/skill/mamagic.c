// dremagic.c //cgy

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="magic"; }

string cast_spell_file(string func)
{
          return CLASS_D("needlegirl") + "/mamagic/" + func;
}


int practice_skill(object me)
{


        if( (int)me->query("atman") < 10 )
                return notify_fail("你的靈力不夠。\n");

        if( (int)me->query("gin") < 30 )
                return notify_fail("你的精神無法集中。\n");

        me->add("atman", -10);
        me->receive_damage("gin", 30);

         write("妳努力研究媚術,似乎頗有績效,皮膚散發出一層光彩..\n");
       return 1;
}
int valid_learn(object me)
{
        if( me->query("family/family_name") != "神織舫" ) {
            tell_object(me, "你並非我門徒, 我無法傳授於你。\n");
            return 0;
        }
        if( !me->query("get_ma",1) ) {
            tell_object(me, "妳未得長老首肯,我不能傳授妳此技。\n");
            return 0;
}
}
