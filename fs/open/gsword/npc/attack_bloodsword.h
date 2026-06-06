void init()
{
  object obj = previous_object();
  if(obj->query("family/family_name") == "血魔一派")
  {
    command("say 你這個叛派弟子，我們仙劍派容不了你這個叛徒！");
    this_object()->kill_ob(obj);
  }
}
