#include "sv_activ_n.h"

//the support vectors; machine learned
float svec_activ_n[NUMSVEC_ACTIV_N][NUM_FEATURES]
      ={{	1.5845441, -0.18404919, 1.0322001, 4},
        {	0.012019857, -0.21903245, 0.024382493, 0.125},
        {	0.022562195, 0.76968193, 0.019550271, 0.08203125},
        {	0.0089770639, 0.2632772, 0.020376287, 0.06640625},
        {	0.0035383657, -0.59068036, 0.0031582362, 0.01171875},
        {	0.0032786233, 0.41106105, 0.036917485, 0.23242188},
        {	0.040927261, -0.79200828, 0.1198609, 0.3828125},
        {	0.024054732, -0.5531913, 0.031328112, 0.140625},
        {	0.014192217, 0.47446144, 0.012063307, 0.060546875},
        {	0.077472128, -0.35445669, 0.1022889, 0.609375},
        {	0.44797719, 0.76985967, 0.32209423, 1.5957031},
        {	0.010054015, 0.87800992, 0.0074740122, 0.029296875},
        {	0.0025594817, -0.34527722, 0.004124274, 0.015625},
        {	0.0087701734, 0.87433648, 0.0080097057, 0.046875},
        {	0.0089667207, 0.43910405, 0.010206878, 0.04296875},
        {	0.0022329222, 0.40169221, 0.0038697715, 0.015625},
        {	0.01766672, 0.8402431, 0.017021131, 0.06640625},
        {	0.024354188, -0.35047841, 0.035460111, 0.15625},
        {	0.0050309971, -0.51949805, 0.018229881, 0.060546875},
        {	0.0084601333, 0.72752714, 0.0448111, 0.15234375},
        {	0.011218843, 0.7166332, 0.019121043, 0.07421875},
        {	0.007283173, -0.89017373, 0.045297835, 0.22460938},
        {	0.02509789, -0.82785469, 0.049537022, 0.1875},
        {	0.0053470945, 0.71630371, 0.015424567, 0.05859375},
        {	0.028365431, 0.67412412, 0.019725533, 0.0859375},
        {	0.060703188, -0.54291618, 0.052172057, 0.33789063},
        {	0.072977178, -0.4926213, 0.071284503, 0.30859375},
        {	0.028644696, 0.48163721, 0.02534971, 0.1484375},
        {	0.0061755115, 0.2321385, 0.01576142, 0.056640625},
        {	0.067328967, 0.163341, 0.25000918, 1.6601563},
        {	0.0080487356, -0.86240512, 0.017455557, 0.083984375},
        {	0.04161939, -0.0038611854, 0.052569944, 0.23632813},
        {	0.0060474738, -0.25363263, 0.0067106625, 0.041015625},
        {	0.012110489, -0.814915, 0.026775837, 0.15234375},
        {	0.091513537, -0.80296707, 0.052955471, 0.26953125},
        {	0.0037736632, 0.42033893, 0.011818382, 0.04296875},
        {	0.01243904, 0.15132605, 0.011456975, 0.056640625},
        {	0.019840077, -0.52210879, 0.045803748, 0.27539063},
        {	0.0035932274, -0.55733103, 0.0067506265, 0.033203125},
        {	0.017191568, 0.43016875, 0.013633815, 0.052734375},
        {	0.030179335, 0.57478201, 0.02118586, 0.08984375},
        {	0.016361875, -0.459658, 0.0300657, 0.15039063},
        {	0.012182963, -0.31565616, 0.016724393, 0.0703125},
        {	0.007774204, 0.60023874, 0.025097895, 0.08203125},
        {	0.020770639, 0.68392354, 0.021062752, 0.095703125},
        {	0.011482228, -0.11271857, 0.019240562, 0.11328125},
        {	0.0067010131, -0.29403979, 0.0075188647, 0.033203125},
        {	0.0082448376, 0.90020239, 0.0079476433, 0.02734375},
        {	0.0061763236, -0.88339168, 0.032278158, 0.10742188},
        {	0.0067494935, -0.18527426, 0.027917935, 0.10546875},
        {	0.036919415, -0.38096213, 0.067419201, 0.27539063},
        {	0.0097276699, 0.87893695, 0.0059090359, 0.03125},
        {	0.01994447, 0.85816801, 0.015580804, 0.0625},
        {	0.017730204, -0.29324946, 0.037870433, 0.16992188},
        {	0.10617062, -0.38284484, 0.032404162, 0.2421875},
        {	0.0049440018, 0.81120324, 0.0072535151, 0.02734375},
        {	0.015928, 0.79179966, 0.015296016, 0.0703125},
        {	0.03230739, -0.57636249, 0.037447818, 0.15039063},
        {	0.057158913, -0.69381207, 0.10130556, 0.296875},
        {	0.0056844805, 0.70337647, 0.013619458, 0.060546875},
        {	0.026871711, 0.53667504, 0.022830719, 0.10742188},
        {	0.032532584, -0.65902257, 0.033087704, 0.14257813},
        {	0.044183843, -0.88155484, 0.071236372, 0.3515625},
        {	0.0044860169, 0.46289593, 0.017436776, 0.05859375},
        {	0.019608529, 0.32345173, 0.018528707, 0.087890625},
        {	0.0079758009, -0.79108912, 0.022206372, 0.15234375},
        {	0.062781587, -0.10684497, 0.095874369, 0.375},
        {	0.011546049, 0.33344683, 0.015915273, 0.060546875},
        {	0.071226336, -0.1460555, 0.069899358, 0.26953125},
        {	0.0024999967, 0.71956795, 0.0044571031, 0.015625},
        {	0.017896062, 0.58024633, 0.02191033, 0.11132813},
        {	0.034303315, -0.1883945, 0.025332727, 0.1171875},
        {	0.14273055, -0.023080099, 0.053464182, 0.24023438},
        {	0.003382541, 0.69463748, 0.0079514878, 0.03125},
        {	0.021502404, 0.62662733, 0.025553776, 0.10351563},
        {	0.01968321, 0.048485637, 0.028125104, 0.13476563},
        {	0.023398731, 0.47964486, 0.025323119, 0.13671875},
        {	0.0071448041, 0.69937617, 0.0047224262, 0.017578125},
        {	0.18586464, -0.44464928, 0.3823989, 2.3515625},
        {	0.021266077, 0.15936518, 0.029403144, 0.125},
        {	0.044967551, 0.077643774, 0.05994435, 0.27539063},
        {	0.0062228465, 0.66329455, 0.0053798505, 0.025390625},
        {	0.025944309, 0.45768067, 0.035475314, 0.15039063},
        {	0.020502904, 0.043227587, 0.021713972, 0.099609375},
        {	0.16754478, -0.080131948, 0.056526858, 0.28125},
        {	0.0077922489, 0.60173237, 0.0062893145, 0.02734375},
        {	0.027989998, 0.60251611, 0.02627177, 0.125},
        {	0.020947266, -0.39910576, 0.026642764, 0.14453125},
        {	0.034448504, -0.60832953, 0.08069247, 0.37695313},
        {	0.031307492, 0.67763835, 0.02643434, 0.109375},
        {	0.044946797, -0.78793901, 0.031972658, 0.13085938},
        {	0.11251914, -0.72077453, 0.076636441, 0.36132813},
        {	0.0056379638, 0.53193015, 0.0033024417, 0.01171875},
        {	0.040185362, 0.40382302, 0.038931444, 0.18945313},
        {	0.028003974, -0.53232986, 0.032936595, 0.1484375},
        {	0.06186159, -0.50603634, 0.08199279, 0.36132813},
        {	0.0018208793, 0.53750873, 0.0012470857, 0.005859375},
        {	0.040928122, 0.51476735, 0.042131279, 0.1640625},
        {	0.037753906, 0.50804937, 0.038110778, 0.17382813},
        {	0.015006667, -0.92307419, 0.019306537, 0.09765625},
        {	0.028501445, 0.27685252, 0.049447693, 0.23828125},
        {	0.003496296, 0.46975803, 0.0044658729, 0.015625},
        {	0.42846173, -0.93394476, 0.36527643, 2.7753906},
        {	0.011651355, 0.2373367, 0.015882974, 0.087890625},
        {	0.030619074, 0.60873067, 0.027037079, 0.14648438},
        {	0.030793292, -0.35443407, 0.025349179, 0.12695313},
        {	0.078921549, -0.3123354, 0.099569485, 0.34960938},
        {	0.0037133663, 0.46426305, 0.003803486, 0.015625},
        {	0.031460207, 0.71114951, 0.021833466, 0.10351563},
        {	0.17862119, -0.54674757, 0.06848073, 0.32421875},
        {	0.021052008, 0.75175059, 0.021518437, 0.08984375},
        {	0.028510684, -0.62151545, 0.026596237, 0.13085938},
        {	0.0048248768, 0.43993744, 0.0052888561, 0.0234375},
        {	0.16971292, 0.20003635, 0.3027828, 2.2050781},
        {	0.031706378, -0.62141699, 0.025074696, 0.125},
        {	0.055655271, 0.36275518, 0.065273449, 0.25585938},
        {	0.0094049359, -0.74060273, 0.032848459, 0.13085938},
        {	0.036615733, -0.72562742, 0.10420828, 0.38671875},
        {	0.0095004523, 0.30854571, 0.015738521, 0.0625},
        {	0.026236443, -0.86211622, 0.022462299, 0.11132813},
        {	1.6994228, -0.22772071, 0.56382269, 2.3710938},
        {	0.55221605, 0.45851928, 0.52206153, 3.0625},
        {	0.0026518835, 0.43998334, 0.0010419796, 0.00390625},
        {	0.46295092, -0.3103494, 0.52659637, 4},
        {	0.017749149, 0.80219775, 0.018733457, 0.08203125},
        {	0.22689183, -0.79186779, 0.25766563, 1.7109375},
        {	1.3792377, 0.6677615, 0.75427222, 3.3222656},
        {	0.64480829, 0.63965553, 0.61339736, 4},
        {	1.5057845, 0.11812632, 0.34734398, 1.6660156},
        {	0.030992843, -0.87399364, 0.11335652, 0.40234375},
        {	0.013056227, 0.77724808, 0.015761808, 0.083984375},
        {	0.73450506, 0.79659563, 0.39729339, 2.0761719},
        {	1.7094822, 0.014472674, 0.56410438, 3.21875},
        {	0.96143425, 0.61721718, 0.51454788, 3.3398438},
        {	0.19896646, 0.75734788, 0.24470147, 1.5527344},
        {	0.017937776, 0.756033, 0.017513948, 0.09375},
        {	1.0781105, 0.11336856, 0.20370038, 0.98242188},
        {	0.53692406, 0.3492589, 0.70799166, 3.4472656},
        {	1.6302634, 0.4486447, 0.94528037, 3.9121094},
        {	0.0085301027, 0.35021892, 0.009068545, 0.037109375},
        {	0.36663374, 0.81208533, 0.42128071, 2.5761719},
        {	0.92711496, -0.0982785, 0.49043, 2.3125},
        {	1.2040305, -0.12844555, 0.67456216, 3.203125},
        {	0.63244355, -0.63458687, 0.24612664, 1.5859375},
        {	1.2004377, 0.19353181, 0.29896897, 1.3613281},
        {	1.8978121, 0.053264514, 0.50017917, 2.7871094},
        {	0.4851903, -0.13662417, 0.51242733, 3.0019531},
        {	1.0802159, 0.24212155, 0.60028714, 2.2792969},
        {	1.2334732, -0.33569616, 0.99606621, 4},
        {	0.84419996, 0.51516312, 0.77014124, 4},
        {	0.029480908, 0.68996716, 0.028274253, 0.11523438},
        {	1.8149719, 0.040550221, 0.70307404, 4},
        {	0.10500949, -0.23353401, 0.2950311, 1.8222656},
        {	0.2674357, 0.046877071, 0.54850149, 2.5976563},
        {	1.0936235, 0.14445363, 0.28490043, 1.3164063},
        {	0.44886416, 0.099049658, 0.4366805, 1.4707031},
        {	0.015841318, -0.30262145, 0.022079319, 0.1015625},
        {	0.83385664, 0.60083956, 0.63344383, 2.9199219},
        {	1.261238, 0.32658976, 0.92810202, 3.1445313},
        {	0.92033297, 0.41766709, 0.36901417, 1.6914063},
        {	0.44911614, 0.11994158, 0.70127481, 4},
        {	0.56389976, 0.091088116, 0.5007745, 3.3945313},
        {	0.47989804, 0.77373087, 0.38681334, 2.71875},
        {	1.0889446, 0.15688752, 0.2408026, 1.3378906}	};
  //the alpha parameters; machine leared parameters
  float alpha_activ_n[NUMSVEC_ACTIV_N]
        ={-0.0115221681919107800,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.0644531740331454880,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.0213791505739925340,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          0.7221399081270805100,
          0.1067256872957110400,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          -0.0499646183485284450,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          0.6095032783946755500,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.6301513384420033300,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.0418565163686470400,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.2208064548781037400,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.1103448681750234000,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          -0.7221399081270805100,
          -0.7221399081270805100,
          -0.7221399081270805100,
          0.7221399081270805100,
          0.7221399081270805100,
          -0.0285771969400777930,
          0.7221399081270805100,
          -0.7032618861279129600,
          0.6797138782614923200,
          -0.7221399081270805100,
          0.7221399081270805100,
          0.7221399081270805100,
          -0.0740444304690735110,
          -0.0002433330930632200,
          0.7221399081270805100,
          -0.1012694343552155200,
          -0.0130358962971650720,
          -0.0629896249475925540,
          -0.0627193674102529130,
          -0.0944039331178402750,
          -0.0834130769666537040,
          -0.3425523649956770900,
          -0.7221399081270805100,
          -0.0567866335137678440,
          -0.0300886793935194710,
          -0.0183456973613220500,
          -0.0602300685888613740,
          -0.7221399081270805100,
          -0.0448992780816656820,
          -0.0312338750623393150,
          -0.0624958157834408430,
          0.7221399081270805100,
          -0.0617411819804516700,
          -0.0410593079012600770,
          -0.0471295473380258370,
          -0.0620425219980632950,
          -0.0141011813731494570,
          -0.0701956841073202860,
          -0.0493487633090448010,
          -0.0328649670279772820,
          -0.0869528314268386700,
          -0.0038751719100862687,
          -0.7221399081270805100,
          -0.0707433424464984640,
          -0.0231733400444127480,
          -0.0331632524776090950,
          -0.0063249078523990093,
          -0.0166873971743915740,
          0.3559716729737431600,
          -0.0291354955940344340,
          -0.0178193967931984660,
          -0.0171504775508402800,
          -0.0166398574685404640,
          -0.0089500011789509296,
          -0.0232748228165618950,
          -0.0132712597158302390};