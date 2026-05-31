 //sing.c

inherit SKILL;

int valid_learn(object me)
{
int mysk,mylv;

        mysk = me->query_skill("sing");
        mylv = me->query("class-level/singer/level");

        if ( mylv > mysk )      return 1;

return 0;
}


string perform_action_file(string song)         //在/daemon/class
{
object me;

        me = this_player();

        if ( me->query("class") != "scholar" )
                return "\n";
        return CLASS_D("singer")+"/songs/"+song;
}
