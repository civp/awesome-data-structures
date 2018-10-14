#include <stdio.h>
#include <math.h>

struct Para{
    char typ;
    float num;
};
typedef struct Para Par; 

int main()
{
    char c;
    while((c = getchar()) != 'E'){
        Par pm, pn;
        float tmp, hum, dew, e, h;
        pm.typ = c;
        scanf("%f", &pm.num);
        scanf(" %c %f", &pn.typ, &pn.num);
        getchar();
        if(pm.typ == 'T' && pn.typ == 'D'){
            tmp = pm.num;
            dew = pn.num;
            e = 6.11 * exp(5417.7530 * ((1.0/273.16) - (1.0/(dew+273.16))));
            h = 0.5555 * (e - 10);
            hum = tmp + h;
        }
        else if(pm.typ == 'D' && pn.typ == 'T'){
            tmp = pn.num;
            dew = pm.num;
            e = 6.11 * exp(5417.7530 * ((1.0/273.16) - (1.0/(dew+273.16))));
            h = 0.5555 * (e - 10);
            hum = tmp + h;
        }
        else if(pm.typ == 'T' && pn.typ == 'H'){
            tmp = pm.num;
            hum = pn.num;
            h = hum - tmp;
            e = h / 0.5555 + 10;
            dew = 1.0 / (-(log(e / 6.11) / 5417.7530) + (1.0/273.16)) - 273.16;
        }
        else if(pm.typ == 'H' && pn.typ == 'T'){
            tmp = pn.num;
            hum = pm.num;
            h = hum - tmp;
            e = h / 0.5555 + 10;
            dew = 1.0 / (-(log(e / 6.11) / 5417.7530) + (1.0/273.16)) - 273.16;
        }
        else if(pm.typ == 'D' && pn.typ == 'H'){
            dew = pm.num;
            hum = pn.num;
            e = 6.11 * exp(5417.7530 * ((1.0/273.16) - (1.0/(dew+273.16))));
            h = (e - 10) * 0.5555;
            tmp = hum - h;
        }
        else if(pm.typ == 'H' && pn.typ == 'D'){
            dew = pn.num;
            hum = pm.num;
            e = 6.11 * exp(5417.7530 * ((1.0/273.16) - (1.0/(dew+273.16))));
            h = (e - 10) * 0.5555;
            tmp = hum - h;
        }
        printf("T %.1f D %.1f H %.1f\n", tmp, dew, hum);
    }
}