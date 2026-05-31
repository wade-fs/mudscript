inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="magic"; }

string conjure_magic_file(string func)
{
  return CLASS_D("taoist") + "/gold-magic/" + func;
}

int conjure_magic (object me, string magic, object target)
{

  if (!wizardp(me) && userp(me))
    {
      tell_object (me, "你不夠資格使用魔界金典。\n");
      return 1;
    }
        if( file_size(conjure_magic_file(magic)+".c") > 0 )
        return conjure_magic_file (magic)->conjure(me,target);
        return notify_fail("沒有這樣法術。\n");
}
void skill_improved(object me)
{

}
