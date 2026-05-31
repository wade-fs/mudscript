int valuecheck(object me)
{
        int gin,kee,sen,egin,ekee,esen;

        gin = me->query("gin");
        kee = me->query("kee");
        sen = me->query("sen");
        egin = me->query("eff_gin");
        ekee = me->query("eff_kee");
        esen = me->query("eff_sen");

        if ( gin < egin || kee < ekee || sen < esen )
                return 1;
        else
                return 0;
}
