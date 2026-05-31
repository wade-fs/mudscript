int kill_jobs(int jobs,object me,object ob,string dir); //jobs:總共多少 me:是誰 ob:誰被殺 dir:路徑

int kill_jobs(int jobs,object me,object ob,string dir)
{
        int i;

                me->set_temp("/"+dir+"/killed/"+ob->query("id")+"",1);
                i = sizeof(me->query_temp("/"+dir+"/killed"));

        if(!i || i != jobs )
                return 0;
        else
                return 1;
}
