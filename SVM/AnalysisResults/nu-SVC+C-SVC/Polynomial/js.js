$(function () {
    $('#container').highcharts({
        chart: {
            type: 'spline'
        },
        title: {
            text: 'Влияние параметра <i>γ<i>'
        },
        subtitle: {
            text: '<b>Ядро:</b> Полиномиальное, <b>Cost</b> = 245, <b>μ</b> = 0.23'
        },
        xAxis: {
            type: 'linear',

            title: {
                text: 'Значение γ'
            },
            min: 0.0,
            max: 1.0
        },
        yAxis: {
            title: {
                text: 'Точность'
            },
            labels: {
                formatter: function () {
                    return this.value + ' %';
                }
            }, 
            min: 0,
            max: 100,
            tickInterval: 10
        },
        tooltip: {
            crosshairs: true,
            shared: true
        },
        plotOptions: {
            spline: {
                marker: {
                    radius: 4,
                    lineColor: '#666666',
                    lineWidth: 1
                }
            }
        },
        series: [{
            name: 'C-SVC',
            data: [[0.001, 11.8],
[0.002, 11.9053],
[0.003, 12.0106],
[0.004, 12.116],
[0.005, 12.2213],
[0.006, 12.3266],
[0.007, 12.4319],
[0.008, 12.5372],
[0.009, 12.6426],
[0.01, 12.7479],
[0.011, 12.8532],
[0.012, 12.9585],
[0.013, 13.0638],
[0.014, 13.1691],
[0.015, 13.2745],
[0.016, 13.3798],
[0.017, 13.4851],
[0.018, 13.5904],
[0.019, 13.6957],
[0.02, 13.8011],
[0.021, 13.9064],
[0.022, 14.0117],
[0.023, 14.117],
[0.024, 14.2223],
[0.025, 14.3277],
[0.026, 14.433],
[0.027, 14.5383],
[0.028, 14.6436],
[0.029, 14.7489],
[0.03, 14.8543],
[0.031, 14.9596],
[0.032, 15.0649],
[0.033, 15.1702],
[0.034, 15.2755],
[0.035, 15.3809],
[0.036, 15.4862],
[0.037, 15.5915],
[0.038, 15.6968],
[0.039, 15.8021],
[0.04, 15.9074],
[0.041, 16.0128],
[0.042, 16.1181],
[0.043, 16.2234],
[0.044, 16.3287],
[0.045, 16.434],
[0.046, 16.5394],
[0.047, 16.6447],
[0.048, 16.75],
[0.049, 16.8553],
[0.05, 16.9606],
[0.051, 17.066],
[0.052, 17.1713],
[0.053, 17.2766],
[0.054, 17.3819],
[0.055, 17.4872],
[0.056, 17.5926],
[0.057, 17.6979],
[0.058, 17.8032],
[0.059, 17.9085],
[0.06, 18.0138],
[0.061, 18.1191],
[0.062, 18.2245],
[0.063, 18.3298],
[0.064, 18.4351],
[0.065, 18.5404],
[0.066, 18.6457],
[0.067, 18.7511],
[0.068, 18.8564],
[0.069, 18.9617],
[0.07, 19.067],
[0.071, 19.1723],
[0.072, 19.2777],
[0.073, 19.383],
[0.074, 19.4883],
[0.075, 19.5936],
[0.076, 19.6989],
[0.077, 19.8043],
[0.078, 19.9096],
[0.079, 20.0149],
[0.08, 20.1202],
[0.081, 20.2255],
[0.082, 20.3309],
[0.083, 20.4362],
[0.084, 20.5415],
[0.085, 20.6468],
[0.086, 20.7521],
[0.087, 20.8574],
[0.088, 20.9628],
[0.089, 21.0681],
[0.09, 21.1734],
[0.091, 21.2787],
[0.092, 21.384],
[0.093, 21.4894],
[0.094, 21.5947],
[0.095, 21.7],
[0.096, 21.8053],
[0.097, 21.9106],
[0.098, 22.016],
[0.099, 22.1213],
[0.1, 22.2266],
[0.101, 22.3319],
[0.102, 22.4372],
[0.103, 22.5426],
[0.104, 22.6479],
[0.105, 22.7532],
[0.106, 22.8585],
[0.107, 22.9638],
[0.108, 23.0691],
[0.109, 23.1745],
[0.11, 23.2798],
[0.111, 23.3851],
[0.112, 23.4904],
[0.113, 23.5957],
[0.114, 23.7011],
[0.115, 23.8064],
[0.116, 23.9117],
[0.117, 24.017],
[0.118, 24.1223],
[0.119, 24.2277],
[0.12, 24.333],
[0.121, 24.4383],
[0.122, 24.5436],
[0.123, 24.6489],
[0.124, 24.7543],
[0.125, 24.8596],
[0.126, 24.9649],
[0.127, 25.0702],
[0.128, 25.1755],
[0.129, 25.2809],
[0.13, 25.3862],
[0.131, 25.4915],
[0.132, 25.5968],
[0.133, 25.7021],
[0.134, 25.8074],
[0.135, 25.9128],
[0.136, 26.0181],
[0.137, 26.1234],
[0.138, 26.2287],
[0.139, 26.334],
[0.14, 26.4394],
[0.141, 26.5447],
[0.142, 26.65],
[0.143, 26.7553],
[0.144, 26.8606],
[0.145, 26.966],
[0.146, 27.0713],
[0.147, 27.1766],
[0.148, 27.2819],
[0.149, 27.3872],
[0.15, 27.4926],
[0.151, 27.5979],
[0.152, 27.7032],
[0.153, 27.8085],
[0.154, 27.9138],
[0.155, 28.0191],
[0.156, 28.1245],
[0.157, 28.2298],
[0.158, 28.3351],
[0.159, 28.4404],
[0.16, 28.5457],
[0.161, 28.6511],
[0.162, 28.7564],
[0.163, 28.8617],
[0.164, 28.967],
[0.165, 29.0723],
[0.166, 29.1777],
[0.167, 29.283],
[0.168, 29.3883],
[0.169, 29.4936],
[0.17, 29.5989],
[0.171, 29.7043],
[0.172, 29.8096],
[0.173, 29.9149],
[0.174, 30.0202],
[0.175, 30.1255],
[0.176, 30.2309],
[0.177, 30.3362],
[0.178, 30.4415],
[0.179, 30.5468],
[0.18, 30.6521],
[0.181, 30.7574],
[0.182, 30.8628],
[0.183, 30.9681],
[0.184, 31.0734],
[0.185, 31.1787],
[0.186, 31.284],
[0.187, 31.3894],
[0.188, 31.4947],
[0.189, 31.6],
[0.19, 31.6],
[0.191, 32.0778],
[0.192, 32.5556],
[0.193, 33.0333],
[0.194, 33.5111],
[0.195, 33.9889],
[0.196, 34.4667],
[0.197, 34.9444],
[0.198, 35.4222],
[0.199, 35.9],
[0.2, 36.3778],
[0.201, 36.8556],
[0.202, 37.3333],
[0.203, 37.8111],
[0.204, 38.2889],
[0.205, 38.7667],
[0.206, 39.2444],
[0.207, 39.7222],
[0.208, 40.2],
[0.209, 40.6778],
[0.21, 41.1556],
[0.211, 41.6333],
[0.212, 42.1111],
[0.213, 42.5889],
[0.214, 43.0667],
[0.215, 43.5444],
[0.216, 44.0222],
[0.217, 44.5],
[0.218, 44.9778],
[0.219, 45.4556],
[0.22, 45.9333],
[0.221, 46.4111],
[0.222, 46.8889],
[0.223, 47.3667],
[0.224, 47.8444],
[0.225, 48.3222],
[0.226, 48.8],
[0.227, 49.2778],
[0.228, 49.7556],
[0.229, 50.2333],
[0.23, 50.7111],
[0.231, 51.1889],
[0.232, 51.6667],
[0.233, 52.1444],
[0.234, 52.6222],
[0.235, 53.1],
[0.236, 53.5778],
[0.237, 54.0556],
[0.238, 54.5333],
[0.239, 55.0111],
[0.24, 55.4889],
[0.241, 55.9667],
[0.242, 56.4444],
[0.243, 56.9222],
[0.244, 57.4],
[0.245, 57.8778],
[0.246, 58.3556],
[0.247, 58.8333],
[0.248, 59.3111],
[0.249, 59.7889],
[0.25, 60.2667],
[0.251, 60.7444],
[0.252, 61.2222],
[0.253, 61.7],
[0.254, 62.1778],
[0.255, 62.6556],
[0.256, 63.1333],
[0.257, 63.6111],
[0.258, 64.0889],
[0.259, 64.5667],
[0.26, 65.0444],
[0.261, 65.5222],
[0.262, 66],
[0.263, 66.4778],
[0.264, 66.9556],
[0.265, 67.4333],
[0.266, 67.9111],
[0.267, 68.3889],
[0.268, 68.8667],
[0.269, 69.3444],
[0.27, 69.8222],
[0.271, 70.3],
[0.272, 70.7778],
[0.273, 71.2556],
[0.274, 71.7333],
[0.275, 72.2111],
[0.276, 72.6889],
[0.277, 73.1667],
[0.278, 73.6444],
[0.279, 74.1222],
[0.28, 74.6],
[0.281, 74.5],
[0.282, 74.4536],
[0.283, 74.4072],
[0.284, 74.3609],
[0.285, 74.3145],
[0.286, 74.2681],
[0.287, 74.2217],
[0.288, 74.1754],
[0.289, 74.129],
[0.29, 74.0826],
[0.291, 74.0362],
[0.292, 73.9899],
[0.293, 73.9435],
[0.294, 73.8971],
[0.295, 73.8507],
[0.296, 73.8043],
[0.297, 73.758],
[0.298, 73.7116],
[0.299, 73.6652],
[0.3, 73.6188],
[0.301, 73.5725],
[0.302, 73.5261],
[0.303, 73.4797],
[0.304, 73.4333],
[0.305, 73.387],
[0.306, 73.3406],
[0.307, 73.2942],
[0.308, 73.2478],
[0.309, 73.2014],
[0.31, 73.1551],
[0.311, 73.1087],
[0.312, 73.0623],
[0.313, 73.0159],
[0.314, 72.9696],
[0.315, 72.9232],
[0.316, 72.8768],
[0.317, 72.8304],
[0.318, 72.7841],
[0.319, 72.7377],
[0.32, 72.6913],
[0.321, 72.6449],
[0.322, 72.5986],
[0.323, 72.5522],
[0.324, 72.5058],
[0.325, 72.4594],
[0.326, 72.413],
[0.327, 72.3667],
[0.328, 72.3203],
[0.329, 72.2739],
[0.33, 72.2275],
[0.331, 72.1812],
[0.332, 72.1348],
[0.333, 72.0884],
[0.334, 72.042],
[0.335, 71.9957],
[0.336, 71.9493],
[0.337, 71.9029],
[0.338, 71.8565],
[0.339, 71.8101],
[0.34, 71.7638],
[0.341, 71.7174],
[0.342, 71.671],
[0.343, 71.6246],
[0.344, 71.5783],
[0.345, 71.5319],
[0.346, 71.4855],
[0.347, 71.4391],
[0.348, 71.3928],
[0.349, 71.3464],
[0.35, 71.3],
[0.351, 71.3],
[0.352, 71.3352],
[0.353, 71.3704],
[0.354, 71.4056],
[0.355, 71.4407],
[0.356, 71.4759],
[0.357, 71.5111],
[0.358, 71.5463],
[0.359, 71.5815],
[0.36, 71.6167],
[0.361, 71.6519],
[0.362, 71.687],
[0.363, 71.7222],
[0.364, 71.7574],
[0.365, 71.7926],
[0.366, 71.8278],
[0.367, 71.863],
[0.368, 71.8981],
[0.369, 71.9333],
[0.37, 71.9685],
[0.371, 72.0037],
[0.372, 72.0389],
[0.373, 72.0741],
[0.374, 72.1093],
[0.375, 72.1444],
[0.376, 72.1796],
[0.377, 72.2148],
[0.378, 72.25],
[0.379, 72.2852],
[0.38, 72.3204],
[0.381, 72.3556],
[0.382, 72.3907],
[0.383, 72.4259],
[0.384, 72.4611],
[0.385, 72.4963],
[0.386, 72.5315],
[0.387, 72.5667],
[0.388, 72.6019],
[0.389, 72.637],
[0.39, 72.6722],
[0.391, 72.7074],
[0.392, 72.7426],
[0.393, 72.7778],
[0.394, 72.813],
[0.395, 72.8481],
[0.396, 72.8833],
[0.397, 72.9185],
[0.398, 72.9537],
[0.399, 72.9889],
[0.4, 73.0241],
[0.401, 73.0593],
[0.402, 73.0944],
[0.403, 73.1296],
[0.404, 73.1648],
[0.405, 73.2],
[0.406, 73.2352],
[0.407, 73.2704],
[0.408, 73.3056],
[0.409, 73.3407],
[0.41, 73.3759],
[0.411, 73.4111],
[0.412, 73.4463],
[0.413, 73.4815],
[0.414, 73.5167],
[0.415, 73.5519],
[0.416, 73.587],
[0.417, 73.6222],
[0.418, 73.6574],
[0.419, 73.6926],
[0.42, 73.7278],
[0.421, 73.763],
[0.422, 73.7981],
[0.423, 73.8333],
[0.424, 73.8685],
[0.425, 73.9037],
[0.426, 73.9389],
[0.427, 73.9741],
[0.428, 74.0093],
[0.429, 74.0444],
[0.43, 74.0796],
[0.431, 74.1148],
[0.432, 74.15],
[0.433, 74.1852],
[0.434, 74.2204],
[0.435, 74.2556],
[0.436, 74.2907],
[0.437, 74.3259],
[0.438, 74.3611],
[0.439, 74.3963],
[0.44, 74.4315],
[0.441, 74.4667],
[0.442, 74.5019],
[0.443, 74.537],
[0.444, 74.5722],
[0.445, 74.6074],
[0.446, 74.6426],
[0.447, 74.6778],
[0.448, 74.713],
[0.449, 74.7481],
[0.45, 74.7833],
[0.451, 74.8185],
[0.452, 74.8537],
[0.453, 74.8889],
[0.454, 74.9241],
[0.455, 74.9593],
[0.456, 74.9944],
[0.457, 75.0296],
[0.458, 75.0648],
[0.459, 75.1],
[0.46, 75.1352],
[0.461, 75.1704],
[0.462, 75.2056],
[0.463, 75.2407],
[0.464, 75.2759],
[0.465, 75.3111],
[0.466, 75.3463],
[0.467, 75.3815],
[0.468, 75.4167],
[0.469, 75.4519],
[0.47, 75.487],
[0.471, 75.5222],
[0.472, 75.5574],
[0.473, 75.5926],
[0.474, 75.6278],
[0.475, 75.663],
[0.476, 75.6981],
[0.477, 75.7333],
[0.478, 75.7685],
[0.479, 75.8037],
[0.48, 75.8389],
[0.481, 75.8741],
[0.482, 75.9093],
[0.483, 75.9444],
[0.484, 75.9796],
[0.485, 76.0148],
[0.486, 76.05],
[0.487, 76.0852],
[0.488, 76.1204],
[0.489, 76.1556],
[0.49, 76.1907],
[0.491, 76.2259],
[0.492, 76.2611],
[0.493, 76.2963],
[0.494, 76.3315],
[0.495, 76.3667],
[0.496, 76.4019],
[0.497, 76.437],
[0.498, 76.4722],
[0.499, 76.5074],
[0.5, 76.5426],
[0.501, 76.5778],
[0.502, 76.613],
[0.503, 76.6481],
[0.504, 76.6833],
[0.505, 76.7185],
[0.506, 76.7537],
[0.507, 76.7889],
[0.508, 76.8241],
[0.509, 76.8593],
[0.51, 76.8944],
[0.511, 76.9296],
[0.512, 76.9648],
[0.513, 77],
[0.514, 77.0352],
[0.515, 77.0704],
[0.516, 77.1056],
[0.517, 77.1407],
[0.518, 77.1759],
[0.519, 77.2111],
[0.52, 77.2463],
[0.521, 77.2815],
[0.522, 77.3167],
[0.523, 77.3519],
[0.524, 77.387],
[0.525, 77.4222],
[0.526, 77.4574],
[0.527, 77.4926],
[0.528, 77.5278],
[0.529, 77.563],
[0.53, 77.5981],
[0.531, 77.6333],
[0.532, 77.6685],
[0.533, 77.7037],
[0.534, 77.7389],
[0.535, 77.7741],
[0.536, 77.8093],
[0.537, 77.8444],
[0.538, 77.8796],
[0.539, 77.9148],
[0.54, 77.95],
[0.541, 77.9852],
[0.542, 78.0204],
[0.543, 78.0556],
[0.544, 78.0907],
[0.545, 78.1259],
[0.546, 78.1611],
[0.547, 78.1963],
[0.548, 78.2315],
[0.549, 78.2667],
[0.55, 78.3019],
[0.551, 78.337],
[0.552, 78.3722],
[0.553, 78.4074],
[0.554, 78.4426],
[0.555, 78.4778],
[0.556, 78.513],
[0.557, 78.5481],
[0.558, 78.5833],
[0.559, 78.6185],
[0.56, 78.6537],
[0.561, 78.6889],
[0.562, 78.7241],
[0.563, 78.7593],
[0.564, 78.7944],
[0.565, 78.8296],
[0.566, 78.8648],
[0.567, 78.9],
[0.568, 78.89],
[0.569, 78.8697],
[0.57, 78.8494],
[0.571, 78.829],
[0.572, 78.8087],
[0.573, 78.7884],
[0.574, 78.7681],
[0.575, 78.7478],
[0.576, 78.7275],
[0.577, 78.7071],
[0.578, 78.6868],
[0.579, 78.6665],
[0.58, 78.6462],
[0.581, 78.6259],
[0.582, 78.6056],
[0.583, 78.5852],
[0.584, 78.5649],
[0.585, 78.5446],
[0.586, 78.5243],
[0.587, 78.504],
[0.588, 78.4837],
[0.589, 78.4633],
[0.59, 78.443],
[0.591, 78.4227],
[0.592, 78.4024],
[0.593, 78.3821],
[0.594, 78.3618],
[0.595, 78.3414],
[0.596, 78.3211],
[0.597, 78.3008],
[0.598, 78.2805],
[0.599, 78.2602],
[0.6, 78.2399],
[0.601, 78.2195],
[0.602, 78.1992],
[0.603, 78.1789],
[0.604, 78.1586],
[0.605, 78.1383],
[0.606, 78.118],
[0.607, 78.0976],
[0.608, 78.0773],
[0.609, 78.057],
[0.61, 78.0367],
[0.611, 78.0164],
[0.612, 77.9961],
[0.613, 77.9757],
[0.614, 77.9554],
[0.615, 77.9351],
[0.616, 77.9148],
[0.617, 77.8945],
[0.618, 77.8742],
[0.619, 77.8538],
[0.62, 77.8335],
[0.621, 77.8132],
[0.622, 77.7929],
[0.623, 77.7726],
[0.624, 77.7523],
[0.625, 77.7319],
[0.626, 77.7116],
[0.627, 77.6913],
[0.628, 77.671],
[0.629, 77.6507],
[0.63, 77.6304],
[0.631, 77.61],
[0.632, 77.5897],
[0.633, 77.5694],
[0.634, 77.5491],
[0.635, 77.5288],
[0.636, 77.5085],
[0.637, 77.4881],
[0.638, 77.4678],
[0.639, 77.4475],
[0.64, 77.4272],
[0.641, 77.4069],
[0.642, 77.3866],
[0.643, 77.3662],
[0.644, 77.3459],
[0.645, 77.3256],
[0.646, 77.3053],
[0.647, 77.285],
[0.648, 77.2647],
[0.649, 77.2443],
[0.65, 77.224],
[0.651, 77.2037],
[0.652, 77.1834],
[0.653, 77.1631],
[0.654, 77.1428],
[0.655, 77.1224],
[0.656, 77.1021],
[0.657, 77.0818],
[0.658, 77.0615],
[0.659, 77.0412],
[0.66, 77.0209],
[0.661, 77.0005],
[0.662, 76.9802],
[0.663, 76.9599],
[0.664, 76.9396],
[0.665, 76.9193],
[0.666, 76.899],
[0.667, 76.8786],
[0.668, 76.8583],
[0.669, 76.838],
[0.67, 76.8177],
[0.671, 76.7974],
[0.672, 76.7771],
[0.673, 76.7567],
[0.674, 76.7364],
[0.675, 76.7161],
[0.676, 76.6958],
[0.677, 76.6755],
[0.678, 76.6552],
[0.679, 76.6348],
[0.68, 76.6145],
[0.681, 76.5942],
[0.682, 76.5739],
[0.683, 76.5536],
[0.684, 76.5333],
[0.685, 76.5129],
[0.686, 76.4926],
[0.687, 76.4723],
[0.688, 76.452],
[0.689, 76.4317],
[0.69, 76.4114],
[0.691, 76.391],
[0.692, 76.3707],
[0.693, 76.3504],
[0.694, 76.3301],
[0.695, 76.3098],
[0.696, 76.2895],
[0.697, 76.2691],
[0.698, 76.2488],
[0.699, 76.2285],
[0.7, 76.2082],
[0.701, 76.1879],
[0.702, 76.1676],
[0.703, 76.1472],
[0.704, 76.1269],
[0.705, 76.1066],
[0.706, 76.0863],
[0.707, 76.066],
[0.708, 76.0457],
[0.709, 76.0253],
[0.71, 76.005],
[0.711, 75.9847],
[0.712, 75.9644],
[0.713, 75.9441],
[0.714, 75.9238],
[0.715, 75.9034],
[0.716, 75.8831],
[0.717, 75.8628],
[0.718, 75.8425],
[0.719, 75.8222],
[0.72, 75.8019],
[0.721, 75.7815],
[0.722, 75.7612],
[0.723, 75.7409],
[0.724, 75.7206],
[0.725, 75.7003],
[0.726, 75.68],
[0.727, 75.6596],
[0.728, 75.6393],
[0.729, 75.619],
[0.73, 75.5987],
[0.731, 75.5784],
[0.732, 75.5581],
[0.733, 75.5377],
[0.734, 75.5174],
[0.735, 75.4971],
[0.736, 75.4768],
[0.737, 75.4565],
[0.738, 75.4362],
[0.739, 75.4158],
[0.74, 75.3955],
[0.741, 75.3752],
[0.742, 75.3549],
[0.743, 75.3346],
[0.744, 75.3143],
[0.745, 75.2939],
[0.746, 75.2736],
[0.747, 75.2533],
[0.748, 75.233],
[0.749, 75.2127],
[0.75, 75.1924],
[0.751, 75.172],
[0.752, 75.1517],
[0.753, 75.1314],
[0.754, 75.1111],
[0.755, 75.0908],
[0.756, 75.0705],
[0.757, 75.0501],
[0.758, 75.0298],
[0.759, 75.0095],
[0.76, 74.9892],
[0.761, 74.9689],
[0.762, 74.9486],
[0.763, 74.9282],
[0.764, 74.9079],
[0.765, 74.8876],
[0.766, 74.8673],
[0.767, 74.847],
[0.768, 74.8267],
[0.769, 74.8063],
[0.77, 74.786],
[0.771, 74.7657],
[0.772, 74.7454],
[0.773, 74.7251],
[0.774, 74.7048],
[0.775, 74.6844],
[0.776, 74.6641],
[0.777, 74.6438],
[0.778, 74.6235],
[0.779, 74.6032],
[0.78, 74.5829],
[0.781, 74.5625],
[0.782, 74.5422],
[0.783, 74.5219],
[0.784, 74.5016],
[0.785, 74.4813],
[0.786, 74.461],
[0.787, 74.4406],
[0.788, 74.4203],
[0.789, 74.4],
[0.79, 74.39],
[0.791, 74.3201],
[0.792, 74.2502],
[0.793, 74.1803],
[0.794, 74.1104],
[0.795, 74.0405],
[0.796, 73.9706],
[0.797, 73.9007],
[0.798, 73.8308],
[0.799, 73.7609],
[0.8, 73.691],
[0.801, 73.6211],
[0.802, 73.5512],
[0.803, 73.4813],
[0.804, 73.4114],
[0.805, 73.3415],
[0.806, 73.2716],
[0.807, 73.2017],
[0.808, 73.1318],
[0.809, 73.0619],
[0.81, 72.992],
[0.811, 72.9221],
[0.812, 72.8522],
[0.813, 72.7823],
[0.814, 72.7124],
[0.815, 72.6425],
[0.816, 72.5726],
[0.817, 72.5027],
[0.818, 72.4328],
[0.819, 72.3629],
[0.82, 72.293],
[0.821, 72.2231],
[0.822, 72.1532],
[0.823, 72.0833],
[0.824, 72.0134],
[0.825, 71.9435],
[0.826, 71.8736],
[0.827, 71.8037],
[0.828, 71.7338],
[0.829, 71.6639],
[0.83, 71.594],
[0.831, 71.5241],
[0.832, 71.4542],
[0.833, 71.3843],
[0.834, 71.3144],
[0.835, 71.2445],
[0.836, 71.1746],
[0.837, 71.1047],
[0.838, 71.0348],
[0.839, 70.9649],
[0.84, 70.895],
[0.841, 70.8251],
[0.842, 70.7552],
[0.843, 70.6853],
[0.844, 70.6154],
[0.845, 70.5455],
[0.846, 70.4756],
[0.847, 70.4057],
[0.848, 70.3358],
[0.849, 70.2659],
[0.85, 70.196],
[0.851, 70.1261],
[0.852, 70.0562],
[0.853, 69.9863],
[0.854, 69.9164],
[0.855, 69.8465],
[0.856, 69.7766],
[0.857, 69.7067],
[0.858, 69.6368],
[0.859, 69.5669],
[0.86, 69.497],
[0.861, 69.4271],
[0.862, 69.3572],
[0.863, 69.2873],
[0.864, 69.2174],
[0.865, 69.1475],
[0.866, 69.0776],
[0.867, 69.0077],
[0.868, 68.9378],
[0.869, 68.8679],
[0.87, 68.798],
[0.871, 68.7281],
[0.872, 68.6582],
[0.873, 68.5883],
[0.874, 68.5184],
[0.875, 68.4485],
[0.876, 68.3786],
[0.877, 68.3087],
[0.878, 68.2388],
[0.879, 68.1689],
[0.88, 68.099],
[0.881, 68.0291],
[0.882, 67.9592],
[0.883, 67.8893],
[0.884, 67.8194],
[0.885, 67.7495],
[0.886, 67.6796],
[0.887, 67.6097],
[0.888, 67.5398],
[0.889, 67.4699],
[0.89, 67.4],
[0.891, 67.39],
[0.892, 67.3699],
[0.893, 67.3498],
[0.894, 67.3297],
[0.895, 67.3096],
[0.896, 67.2895],
[0.897, 67.2694],
[0.898, 67.2494],
[0.899, 67.2293],
[0.9, 67.2092],
[0.901, 67.1891],
[0.902, 67.169],
[0.903, 67.1489],
[0.904, 67.1288],
[0.905, 67.1087],
[0.906, 67.0886],
[0.907, 67.0685],
[0.908, 67.0484],
[0.909, 67.0283],
[0.91, 67.0083],
[0.911, 66.9882],
[0.912, 66.9681],
[0.913, 66.948],
[0.914, 66.9279],
[0.915, 66.9078],
[0.916, 66.8877],
[0.917, 66.8676],
[0.918, 66.8475],
[0.919, 66.8274],
[0.92, 66.8073],
[0.921, 66.7872],
[0.922, 66.7672],
[0.923, 66.7471],
[0.924, 66.727],
[0.925, 66.7069],
[0.926, 66.6868],
[0.927, 66.6667],
[0.928, 66.6466],
[0.929, 66.6265],
[0.93, 66.6064],
[0.931, 66.5863],
[0.932, 66.5662],
[0.933, 66.5461],
[0.934, 66.5261],
[0.935, 66.506],
[0.936, 66.4859],
[0.937, 66.4658],
[0.938, 66.4457],
[0.939, 66.4256],
[0.94, 66.4055],
[0.941, 66.3854],
[0.942, 66.3653],
[0.943, 66.3452],
[0.944, 66.3251],
[0.945, 66.305],
[0.946, 66.285],
[0.947, 66.2649],
[0.948, 66.2448],
[0.949, 66.2247],
[0.95, 66.2046],
[0.951, 66.1845],
[0.952, 66.1644],
[0.953, 66.1443],
[0.954, 66.1242],
[0.955, 66.1041],
[0.956, 66.084],
[0.957, 66.0639],
[0.958, 66.0439],
[0.959, 66.0238],
[0.96, 66.0037],
[0.961, 65.9836],
[0.962, 65.9635],
[0.963, 65.9434],
[0.964, 65.9233],
[0.965, 65.9032],
[0.966, 65.8831],
[0.967, 65.863],
[0.968, 65.8429],
[0.969, 65.8228],
[0.97, 65.8028],
[0.971, 65.7827],
[0.972, 65.7626],
[0.973, 65.7425],
[0.974, 65.7224],
[0.975, 65.7023],
[0.976, 65.6822],
[0.977, 65.6621],
[0.978, 65.642],
[0.979, 65.6219],
[0.98, 65.6018],
[0.981, 65.5817],
[0.982, 65.5617],
[0.983, 65.5416],
[0.984, 65.5215],
[0.985, 65.5014],
[0.986, 65.4813],
[0.987, 65.4612],
[0.988, 65.4411],
[0.989, 65.421],
[0.99, 65.4009],
[0.991, 65.3808],
[0.992, 65.3607],
[0.993, 65.3406],
[0.994, 65.3206],
[0.995, 65.3005],
[0.996, 65.2804],
[0.997, 65.2603],
[0.998, 65.2402],
[0.999, 65.2201],
[1, 65.2]]
        }, {
            name: 'nu-SVC',
            data: [[0.001, 76.5],
[0.002, 76.5057],
[0.003, 76.5115],
[0.004, 76.5172],
[0.005, 76.5229],
[0.006, 76.5287],
[0.007, 76.5344],
[0.008, 76.5401],
[0.009, 76.5459],
[0.01, 76.5516],
[0.011, 76.5573],
[0.012, 76.5631],
[0.013, 76.5688],
[0.014, 76.5745],
[0.015, 76.5803],
[0.016, 76.586],
[0.017, 76.5917],
[0.018, 76.5975],
[0.019, 76.6032],
[0.02, 76.6089],
[0.021, 76.6146],
[0.022, 76.6204],
[0.023, 76.6261],
[0.024, 76.6318],
[0.025, 76.6376],
[0.026, 76.6433],
[0.027, 76.649],
[0.028, 76.6548],
[0.029, 76.6605],
[0.03, 76.6662],
[0.031, 76.672],
[0.032, 76.6777],
[0.033, 76.6834],
[0.034, 76.6892],
[0.035, 76.6949],
[0.036, 76.7006],
[0.037, 76.7064],
[0.038, 76.7121],
[0.039, 76.7178],
[0.04, 76.7236],
[0.041, 76.7293],
[0.042, 76.735],
[0.043, 76.7408],
[0.044, 76.7465],
[0.045, 76.7522],
[0.046, 76.758],
[0.047, 76.7637],
[0.048, 76.7694],
[0.049, 76.7752],
[0.05, 76.7809],
[0.051, 76.7866],
[0.052, 76.7924],
[0.053, 76.7981],
[0.054, 76.8038],
[0.055, 76.8096],
[0.056, 76.8153],
[0.057, 76.821],
[0.058, 76.8268],
[0.059, 76.8325],
[0.06, 76.8382],
[0.061, 76.8439],
[0.062, 76.8497],
[0.063, 76.8554],
[0.064, 76.8611],
[0.065, 76.8669],
[0.066, 76.8726],
[0.067, 76.8783],
[0.068, 76.8841],
[0.069, 76.8898],
[0.07, 76.8955],
[0.071, 76.9013],
[0.072, 76.907],
[0.073, 76.9127],
[0.074, 76.9185],
[0.075, 76.9242],
[0.076, 76.9299],
[0.077, 76.9357],
[0.078, 76.9414],
[0.079, 76.9471],
[0.08, 76.9529],
[0.081, 76.9586],
[0.082, 76.9643],
[0.083, 76.9701],
[0.084, 76.9758],
[0.085, 76.9815],
[0.086, 76.9873],
[0.087, 76.993],
[0.088, 76.9987],
[0.089, 77.0045],
[0.09, 77.0102],
[0.091, 77.0159],
[0.092, 77.0217],
[0.093, 77.0274],
[0.094, 77.0331],
[0.095, 77.0389],
[0.096, 77.0446],
[0.097, 77.0503],
[0.098, 77.0561],
[0.099, 77.0618],
[0.1, 77.0675],
[0.101, 77.0732],
[0.102, 77.079],
[0.103, 77.0847],
[0.104, 77.0904],
[0.105, 77.0962],
[0.106, 77.1019],
[0.107, 77.1076],
[0.108, 77.1134],
[0.109, 77.1191],
[0.11, 77.1248],
[0.111, 77.1306],
[0.112, 77.1363],
[0.113, 77.142],
[0.114, 77.1478],
[0.115, 77.1535],
[0.116, 77.1592],
[0.117, 77.165],
[0.118, 77.1707],
[0.119, 77.1764],
[0.12, 77.1822],
[0.121, 77.1879],
[0.122, 77.1936],
[0.123, 77.1994],
[0.124, 77.2051],
[0.125, 77.2108],
[0.126, 77.2166],
[0.127, 77.2223],
[0.128, 77.228],
[0.129, 77.2338],
[0.13, 77.2395],
[0.131, 77.2452],
[0.132, 77.251],
[0.133, 77.2567],
[0.134, 77.2624],
[0.135, 77.2682],
[0.136, 77.2739],
[0.137, 77.2796],
[0.138, 77.2854],
[0.139, 77.2911],
[0.14, 77.2968],
[0.141, 77.3025],
[0.142, 77.3083],
[0.143, 77.314],
[0.144, 77.3197],
[0.145, 77.3255],
[0.146, 77.3312],
[0.147, 77.3369],
[0.148, 77.3427],
[0.149, 77.3484],
[0.15, 77.3541],
[0.151, 77.3599],
[0.152, 77.3656],
[0.153, 77.3713],
[0.154, 77.3771],
[0.155, 77.3828],
[0.156, 77.3885],
[0.157, 77.3943],
[0.158, 77.4],
[0.159, 77.41],
[0.16, 77.4272],
[0.161, 77.4444],
[0.162, 77.4616],
[0.163, 77.4788],
[0.164, 77.496],
[0.165, 77.5132],
[0.166, 77.5304],
[0.167, 77.5476],
[0.168, 77.5648],
[0.169, 77.582],
[0.17, 77.5992],
[0.171, 77.6164],
[0.172, 77.6336],
[0.173, 77.6508],
[0.174, 77.668],
[0.175, 77.6852],
[0.176, 77.7024],
[0.177, 77.7196],
[0.178, 77.7368],
[0.179, 77.754],
[0.18, 77.7712],
[0.181, 77.7884],
[0.182, 77.8056],
[0.183, 77.8228],
[0.184, 77.84],
[0.185, 77.8572],
[0.186, 77.8744],
[0.187, 77.8916],
[0.188, 77.9088],
[0.189, 77.926],
[0.19, 77.9432],
[0.191, 77.9604],
[0.192, 77.9776],
[0.193, 77.9948],
[0.194, 78.012],
[0.195, 78.0292],
[0.196, 78.0464],
[0.197, 78.0636],
[0.198, 78.0808],
[0.199, 78.098],
[0.2, 78.1152],
[0.201, 78.1324],
[0.202, 78.1496],
[0.203, 78.1668],
[0.204, 78.184],
[0.205, 78.2012],
[0.206, 78.2184],
[0.207, 78.2356],
[0.208, 78.2528],
[0.209, 78.27],
[0.21, 78.2872],
[0.211, 78.3044],
[0.212, 78.3216],
[0.213, 78.3388],
[0.214, 78.356],
[0.215, 78.3732],
[0.216, 78.3904],
[0.217, 78.4076],
[0.218, 78.4248],
[0.219, 78.442],
[0.22, 78.4592],
[0.221, 78.4764],
[0.222, 78.4936],
[0.223, 78.5108],
[0.224, 78.528],
[0.225, 78.5452],
[0.226, 78.5624],
[0.227, 78.5796],
[0.228, 78.5968],
[0.229, 78.614],
[0.23, 78.6312],
[0.231, 78.6484],
[0.232, 78.6656],
[0.233, 78.6828],
[0.234, 78.7],
[0.235, 78.7172],
[0.236, 78.7344],
[0.237, 78.7516],
[0.238, 78.7688],
[0.239, 78.786],
[0.24, 78.8032],
[0.241, 78.8204],
[0.242, 78.8376],
[0.243, 78.8548],
[0.244, 78.872],
[0.245, 78.8892],
[0.246, 78.9064],
[0.247, 78.9236],
[0.248, 78.9408],
[0.249, 78.958],
[0.25, 78.9752],
[0.251, 78.9924],
[0.252, 79.0096],
[0.253, 79.0268],
[0.254, 79.044],
[0.255, 79.0612],
[0.256, 79.0784],
[0.257, 79.0956],
[0.258, 79.1128],
[0.259, 79.13],
[0.26, 79.1472],
[0.261, 79.1644],
[0.262, 79.1816],
[0.263, 79.1988],
[0.264, 79.216],
[0.265, 79.2332],
[0.266, 79.2504],
[0.267, 79.2676],
[0.268, 79.2848],
[0.269, 79.302],
[0.27, 79.3192],
[0.271, 79.3364],
[0.272, 79.3536],
[0.273, 79.3708],
[0.274, 79.388],
[0.275, 79.4052],
[0.276, 79.4224],
[0.277, 79.4396],
[0.278, 79.4568],
[0.279, 79.474],
[0.28, 79.4912],
[0.281, 79.5084],
[0.282, 79.5256],
[0.283, 79.5428],
[0.284, 79.56],
[0.285, 79.55],
[0.286, 79.5227],
[0.287, 79.4954],
[0.288, 79.4681],
[0.289, 79.4408],
[0.29, 79.4135],
[0.291, 79.3862],
[0.292, 79.3589],
[0.293, 79.3316],
[0.294, 79.3043],
[0.295, 79.277],
[0.296, 79.2497],
[0.297, 79.2224],
[0.298, 79.1951],
[0.299, 79.1678],
[0.3, 79.1405],
[0.301, 79.1132],
[0.302, 79.0859],
[0.303, 79.0586],
[0.304, 79.0313],
[0.305, 79.004],
[0.306, 78.9767],
[0.307, 78.9494],
[0.308, 78.9221],
[0.309, 78.8948],
[0.31, 78.8675],
[0.311, 78.8402],
[0.312, 78.8129],
[0.313, 78.7856],
[0.314, 78.7583],
[0.315, 78.731],
[0.316, 78.7037],
[0.317, 78.6763],
[0.318, 78.649],
[0.319, 78.6217],
[0.32, 78.5944],
[0.321, 78.5671],
[0.322, 78.5398],
[0.323, 78.5125],
[0.324, 78.4852],
[0.325, 78.4579],
[0.326, 78.4306],
[0.327, 78.4033],
[0.328, 78.376],
[0.329, 78.3487],
[0.33, 78.3214],
[0.331, 78.2941],
[0.332, 78.2668],
[0.333, 78.2395],
[0.334, 78.2122],
[0.335, 78.1849],
[0.336, 78.1576],
[0.337, 78.1303],
[0.338, 78.103],
[0.339, 78.0757],
[0.34, 78.0484],
[0.341, 78.0211],
[0.342, 77.9938],
[0.343, 77.9665],
[0.344, 77.9392],
[0.345, 77.9119],
[0.346, 77.8846],
[0.347, 77.8573],
[0.348, 77.83],
[0.349, 77.8027],
[0.35, 77.7754],
[0.351, 77.7481],
[0.352, 77.7208],
[0.353, 77.6935],
[0.354, 77.6662],
[0.355, 77.6389],
[0.356, 77.6116],
[0.357, 77.5843],
[0.358, 77.557],
[0.359, 77.5297],
[0.36, 77.5024],
[0.361, 77.4751],
[0.362, 77.4478],
[0.363, 77.4205],
[0.364, 77.3932],
[0.365, 77.3659],
[0.366, 77.3386],
[0.367, 77.3113],
[0.368, 77.284],
[0.369, 77.2567],
[0.37, 77.2294],
[0.371, 77.2021],
[0.372, 77.1748],
[0.373, 77.1475],
[0.374, 77.1202],
[0.375, 77.0929],
[0.376, 77.0656],
[0.377, 77.0383],
[0.378, 77.011],
[0.379, 76.9837],
[0.38, 76.9563],
[0.381, 76.929],
[0.382, 76.9017],
[0.383, 76.8744],
[0.384, 76.8471],
[0.385, 76.8198],
[0.386, 76.7925],
[0.387, 76.7652],
[0.388, 76.7379],
[0.389, 76.7106],
[0.39, 76.6833],
[0.391, 76.656],
[0.392, 76.6287],
[0.393, 76.6014],
[0.394, 76.5741],
[0.395, 76.5468],
[0.396, 76.5195],
[0.397, 76.4922],
[0.398, 76.4649],
[0.399, 76.4376],
[0.4, 76.4103],
[0.401, 76.383],
[0.402, 76.3557],
[0.403, 76.3284],
[0.404, 76.3011],
[0.405, 76.2738],
[0.406, 76.2465],
[0.407, 76.2192],
[0.408, 76.1919],
[0.409, 76.1646],
[0.41, 76.1373],
[0.411, 76.11],
[0.412, 76.1],
[0.413, 76.07],
[0.414, 76.0399],
[0.415, 76.0099],
[0.416, 75.9798],
[0.417, 75.9498],
[0.418, 75.9198],
[0.419, 75.8897],
[0.42, 75.8597],
[0.421, 75.8297],
[0.422, 75.7996],
[0.423, 75.7696],
[0.424, 75.7395],
[0.425, 75.7095],
[0.426, 75.6795],
[0.427, 75.6494],
[0.428, 75.6194],
[0.429, 75.5894],
[0.43, 75.5593],
[0.431, 75.5293],
[0.432, 75.4992],
[0.433, 75.4692],
[0.434, 75.4392],
[0.435, 75.4091],
[0.436, 75.3791],
[0.437, 75.3491],
[0.438, 75.319],
[0.439, 75.289],
[0.44, 75.2589],
[0.441, 75.2289],
[0.442, 75.1989],
[0.443, 75.1688],
[0.444, 75.1388],
[0.445, 75.1088],
[0.446, 75.0787],
[0.447, 75.0487],
[0.448, 75.0186],
[0.449, 74.9886],
[0.45, 74.9586],
[0.451, 74.9285],
[0.452, 74.8985],
[0.453, 74.8685],
[0.454, 74.8384],
[0.455, 74.8084],
[0.456, 74.7783],
[0.457, 74.7483],
[0.458, 74.7183],
[0.459, 74.6882],
[0.46, 74.6582],
[0.461, 74.6282],
[0.462, 74.5981],
[0.463, 74.5681],
[0.464, 74.538],
[0.465, 74.508],
[0.466, 74.478],
[0.467, 74.4479],
[0.468, 74.4179],
[0.469, 74.3879],
[0.47, 74.3578],
[0.471, 74.3278],
[0.472, 74.2977],
[0.473, 74.2677],
[0.474, 74.2377],
[0.475, 74.2076],
[0.476, 74.1776],
[0.477, 74.1476],
[0.478, 74.1175],
[0.479, 74.0875],
[0.48, 74.0574],
[0.481, 74.0274],
[0.482, 73.9974],
[0.483, 73.9673],
[0.484, 73.9373],
[0.485, 73.9073],
[0.486, 73.8772],
[0.487, 73.8472],
[0.488, 73.8171],
[0.489, 73.7871],
[0.49, 73.7571],
[0.491, 73.727],
[0.492, 73.697],
[0.493, 73.667],
[0.494, 73.6369],
[0.495, 73.6069],
[0.496, 73.5768],
[0.497, 73.5468],
[0.498, 73.5168],
[0.499, 73.4867],
[0.5, 73.4567],
[0.501, 73.4267],
[0.502, 73.3966],
[0.503, 73.3666],
[0.504, 73.3365],
[0.505, 73.3065],
[0.506, 73.2765],
[0.507, 73.2464],
[0.508, 73.2164],
[0.509, 73.1864],
[0.51, 73.1563],
[0.511, 73.1263],
[0.512, 73.0962],
[0.513, 73.0662],
[0.514, 73.0362],
[0.515, 73.0061],
[0.516, 72.9761],
[0.517, 72.9461],
[0.518, 72.916],
[0.519, 72.886],
[0.52, 72.8559],
[0.521, 72.8259],
[0.522, 72.7959],
[0.523, 72.7658],
[0.524, 72.7358],
[0.525, 72.7058],
[0.526, 72.6757],
[0.527, 72.6457],
[0.528, 72.6156],
[0.529, 72.5856],
[0.53, 72.5556],
[0.531, 72.5255],
[0.532, 72.4955],
[0.533, 72.4655],
[0.534, 72.4354],
[0.535, 72.4054],
[0.536, 72.3753],
[0.537, 72.3453],
[0.538, 72.3153],
[0.539, 72.2852],
[0.54, 72.2552],
[0.541, 72.2252],
[0.542, 72.1951],
[0.543, 72.1651],
[0.544, 72.135],
[0.545, 72.105],
[0.546, 72.075],
[0.547, 72.0449],
[0.548, 72.0149],
[0.549, 71.9848],
[0.55, 71.9548],
[0.551, 71.9248],
[0.552, 71.8947],
[0.553, 71.8647],
[0.554, 71.8347],
[0.555, 71.8046],
[0.556, 71.7746],
[0.557, 71.7445],
[0.558, 71.7145],
[0.559, 71.6845],
[0.56, 71.6544],
[0.561, 71.6244],
[0.562, 71.5944],
[0.563, 71.5643],
[0.564, 71.5343],
[0.565, 71.5042],
[0.566, 71.4742],
[0.567, 71.4442],
[0.568, 71.4141],
[0.569, 71.3841],
[0.57, 71.3541],
[0.571, 71.324],
[0.572, 71.294],
[0.573, 71.2639],
[0.574, 71.2339],
[0.575, 71.2039],
[0.576, 71.1738],
[0.577, 71.1438],
[0.578, 71.1138],
[0.579, 71.0837],
[0.58, 71.0537],
[0.581, 71.0236],
[0.582, 70.9936],
[0.583, 70.9636],
[0.584, 70.9335],
[0.585, 70.9035],
[0.586, 70.8735],
[0.587, 70.8434],
[0.588, 70.8134],
[0.589, 70.7833],
[0.59, 70.7533],
[0.591, 70.7233],
[0.592, 70.6932],
[0.593, 70.6632],
[0.594, 70.6332],
[0.595, 70.6031],
[0.596, 70.5731],
[0.597, 70.543],
[0.598, 70.513],
[0.599, 70.483],
[0.6, 70.4529],
[0.601, 70.4229],
[0.602, 70.3929],
[0.603, 70.3628],
[0.604, 70.3328],
[0.605, 70.3027],
[0.606, 70.2727],
[0.607, 70.2427],
[0.608, 70.2126],
[0.609, 70.1826],
[0.61, 70.1526],
[0.611, 70.1225],
[0.612, 70.0925],
[0.613, 70.0624],
[0.614, 70.0324],
[0.615, 70.0024],
[0.616, 69.9723],
[0.617, 69.9423],
[0.618, 69.9123],
[0.619, 69.8822],
[0.62, 69.8522],
[0.621, 69.8221],
[0.622, 69.7921],
[0.623, 69.7621],
[0.624, 69.732],
[0.625, 69.702],
[0.626, 69.672],
[0.627, 69.6419],
[0.628, 69.6119],
[0.629, 69.5818],
[0.63, 69.5518],
[0.631, 69.5218],
[0.632, 69.4917],
[0.633, 69.4617],
[0.634, 69.4317],
[0.635, 69.4016],
[0.636, 69.3716],
[0.637, 69.3415],
[0.638, 69.3115],
[0.639, 69.2815],
[0.64, 69.2514],
[0.641, 69.2214],
[0.642, 69.1914],
[0.643, 69.1613],
[0.644, 69.1313],
[0.645, 69.1012],
[0.646, 69.0712],
[0.647, 69.0412],
[0.648, 69.0111],
[0.649, 68.9811],
[0.65, 68.9511],
[0.651, 68.921],
[0.652, 68.891],
[0.653, 68.8609],
[0.654, 68.8309],
[0.655, 68.8009],
[0.656, 68.7708],
[0.657, 68.7408],
[0.658, 68.7108],
[0.659, 68.6807],
[0.66, 68.6507],
[0.661, 68.6206],
[0.662, 68.5906],
[0.663, 68.5606],
[0.664, 68.5305],
[0.665, 68.5005],
[0.666, 68.4705],
[0.667, 68.4404],
[0.668, 68.4104],
[0.669, 68.3803],
[0.67, 68.3503],
[0.671, 68.3203],
[0.672, 68.2902],
[0.673, 68.2602],
[0.674, 68.2302],
[0.675, 68.2001],
[0.676, 68.1701],
[0.677, 68.14],
[0.678, 68.11],
[0.679, 68.12],
[0.68, 68.1397],
[0.681, 68.1593],
[0.682, 68.179],
[0.683, 68.1987],
[0.684, 68.2184],
[0.685, 68.238],
[0.686, 68.2577],
[0.687, 68.2774],
[0.688, 68.2971],
[0.689, 68.3167],
[0.69, 68.3364],
[0.691, 68.3561],
[0.692, 68.3758],
[0.693, 68.3954],
[0.694, 68.4151],
[0.695, 68.4348],
[0.696, 68.4544],
[0.697, 68.4741],
[0.698, 68.4938],
[0.699, 68.5135],
[0.7, 68.5331],
[0.701, 68.5528],
[0.702, 68.5725],
[0.703, 68.5922],
[0.704, 68.6118],
[0.705, 68.6315],
[0.706, 68.6512],
[0.707, 68.6708],
[0.708, 68.6905],
[0.709, 68.7102],
[0.71, 68.7299],
[0.711, 68.7495],
[0.712, 68.7692],
[0.713, 68.7889],
[0.714, 68.8086],
[0.715, 68.8282],
[0.716, 68.8479],
[0.717, 68.8676],
[0.718, 68.8873],
[0.719, 68.9069],
[0.72, 68.9266],
[0.721, 68.9463],
[0.722, 68.9659],
[0.723, 68.9856],
[0.724, 69.0053],
[0.725, 69.025],
[0.726, 69.0446],
[0.727, 69.0643],
[0.728, 69.084],
[0.729, 69.1037],
[0.73, 69.1233],
[0.731, 69.143],
[0.732, 69.1627],
[0.733, 69.1824],
[0.734, 69.202],
[0.735, 69.2217],
[0.736, 69.2414],
[0.737, 69.261],
[0.738, 69.2807],
[0.739, 69.3004],
[0.74, 69.3201],
[0.741, 69.3397],
[0.742, 69.3594],
[0.743, 69.3791],
[0.744, 69.3988],
[0.745, 69.4184],
[0.746, 69.4381],
[0.747, 69.4578],
[0.748, 69.4775],
[0.749, 69.4971],
[0.75, 69.5168],
[0.751, 69.5365],
[0.752, 69.5561],
[0.753, 69.5758],
[0.754, 69.5955],
[0.755, 69.6152],
[0.756, 69.6348],
[0.757, 69.6545],
[0.758, 69.6742],
[0.759, 69.6939],
[0.76, 69.7135],
[0.761, 69.7332],
[0.762, 69.7529],
[0.763, 69.7725],
[0.764, 69.7922],
[0.765, 69.8119],
[0.766, 69.8316],
[0.767, 69.8512],
[0.768, 69.8709],
[0.769, 69.8906],
[0.77, 69.9103],
[0.771, 69.9299],
[0.772, 69.9496],
[0.773, 69.9693],
[0.774, 69.989],
[0.775, 70.0086],
[0.776, 70.0283],
[0.777, 70.048],
[0.778, 70.0676],
[0.779, 70.0873],
[0.78, 70.107],
[0.781, 70.1267],
[0.782, 70.1463],
[0.783, 70.166],
[0.784, 70.1857],
[0.785, 70.2054],
[0.786, 70.225],
[0.787, 70.2447],
[0.788, 70.2644],
[0.789, 70.2841],
[0.79, 70.3037],
[0.791, 70.3234],
[0.792, 70.3431],
[0.793, 70.3627],
[0.794, 70.3824],
[0.795, 70.4021],
[0.796, 70.4218],
[0.797, 70.4414],
[0.798, 70.4611],
[0.799, 70.4808],
[0.8, 70.5005],
[0.801, 70.5201],
[0.802, 70.5398],
[0.803, 70.5595],
[0.804, 70.5792],
[0.805, 70.5988],
[0.806, 70.6185],
[0.807, 70.6382],
[0.808, 70.6578],
[0.809, 70.6775],
[0.81, 70.6972],
[0.811, 70.7169],
[0.812, 70.7365],
[0.813, 70.7562],
[0.814, 70.7759],
[0.815, 70.7956],
[0.816, 70.8152],
[0.817, 70.8349],
[0.818, 70.8546],
[0.819, 70.8742],
[0.82, 70.8939],
[0.821, 70.9136],
[0.822, 70.9333],
[0.823, 70.9529],
[0.824, 70.9726],
[0.825, 70.9923],
[0.826, 71.012],
[0.827, 71.0316],
[0.828, 71.0513],
[0.829, 71.071],
[0.83, 71.0907],
[0.831, 71.1103],
[0.832, 71.13],
[0.833, 71.1386],
[0.834, 71.1473],
[0.835, 71.1559],
[0.836, 71.1645],
[0.837, 71.1732],
[0.838, 71.1818],
[0.839, 71.1904],
[0.84, 71.199],
[0.841, 71.2077],
[0.842, 71.2163],
[0.843, 71.2249],
[0.844, 71.2336],
[0.845, 71.2422],
[0.846, 71.2508],
[0.847, 71.2595],
[0.848, 71.2681],
[0.849, 71.2767],
[0.85, 71.2854],
[0.851, 71.294],
[0.852, 71.3026],
[0.853, 71.3113],
[0.854, 71.3199],
[0.855, 71.3285],
[0.856, 71.3371],
[0.857, 71.3458],
[0.858, 71.3544],
[0.859, 71.363],
[0.86, 71.3717],
[0.861, 71.3803],
[0.862, 71.3889],
[0.863, 71.3976],
[0.864, 71.4062],
[0.865, 71.4148],
[0.866, 71.4235],
[0.867, 71.4321],
[0.868, 71.4407],
[0.869, 71.4493],
[0.87, 71.458],
[0.871, 71.4666],
[0.872, 71.4752],
[0.873, 71.4839],
[0.874, 71.4925],
[0.875, 71.5011],
[0.876, 71.5098],
[0.877, 71.5184],
[0.878, 71.527],
[0.879, 71.5357],
[0.88, 71.5443],
[0.881, 71.5529],
[0.882, 71.5615],
[0.883, 71.5702],
[0.884, 71.5788],
[0.885, 71.5874],
[0.886, 71.5961],
[0.887, 71.6047],
[0.888, 71.6133],
[0.889, 71.622],
[0.89, 71.6306],
[0.891, 71.6392],
[0.892, 71.6479],
[0.893, 71.6565],
[0.894, 71.6651],
[0.895, 71.6737],
[0.896, 71.6824],
[0.897, 71.691],
[0.898, 71.6996],
[0.899, 71.7083],
[0.9, 71.7169],
[0.901, 71.7255],
[0.902, 71.7342],
[0.903, 71.7428],
[0.904, 71.7514],
[0.905, 71.7601],
[0.906, 71.7687],
[0.907, 71.7773],
[0.908, 71.786],
[0.909, 71.7946],
[0.91, 71.8032],
[0.911, 71.8118],
[0.912, 71.8205],
[0.913, 71.8291],
[0.914, 71.8377],
[0.915, 71.8464],
[0.916, 71.855],
[0.917, 71.8636],
[0.918, 71.8723],
[0.919, 71.8809],
[0.92, 71.8895],
[0.921, 71.8982],
[0.922, 71.9068],
[0.923, 71.9154],
[0.924, 71.924],
[0.925, 71.9327],
[0.926, 71.9413],
[0.927, 71.9499],
[0.928, 71.9586],
[0.929, 71.9672],
[0.93, 71.9758],
[0.931, 71.9845],
[0.932, 71.9931],
[0.933, 72.0017],
[0.934, 72.0104],
[0.935, 72.019],
[0.936, 72.0276],
[0.937, 72.0362],
[0.938, 72.0449],
[0.939, 72.0535],
[0.94, 72.0621],
[0.941, 72.0708],
[0.942, 72.0794],
[0.943, 72.088],
[0.944, 72.0967],
[0.945, 72.1053],
[0.946, 72.1139],
[0.947, 72.1226],
[0.948, 72.1312],
[0.949, 72.1398],
[0.95, 72.1485],
[0.951, 72.1571],
[0.952, 72.1657],
[0.953, 72.1743],
[0.954, 72.183],
[0.955, 72.1916],
[0.956, 72.2002],
[0.957, 72.2089],
[0.958, 72.2175],
[0.959, 72.2261],
[0.96, 72.2348],
[0.961, 72.2434],
[0.962, 72.252],
[0.963, 72.2607],
[0.964, 72.2693],
[0.965, 72.2779],
[0.966, 72.2865],
[0.967, 72.2952],
[0.968, 72.3038],
[0.969, 72.3124],
[0.97, 72.3211],
[0.971, 72.3297],
[0.972, 72.3383],
[0.973, 72.347],
[0.974, 72.3556],
[0.975, 72.3642],
[0.976, 72.3729],
[0.977, 72.3815],
[0.978, 72.3901],
[0.979, 72.3987],
[0.98, 72.4074],
[0.981, 72.416],
[0.982, 72.4246],
[0.983, 72.4333],
[0.984, 72.4419],
[0.985, 72.4505],
[0.986, 72.4592],
[0.987, 72.4678],
[0.988, 72.4764],
[0.989, 72.4851],
[0.99, 72.4937],
[0.991, 72.5023],
[0.992, 72.511],
[0.993, 72.5196],
[0.994, 72.5282],
[0.995, 72.5368],
[0.996, 72.5455],
[0.997, 72.5541],
[0.998, 72.5627],
[0.999, 72.5714],
[1, 72.58]]
        }/*, {
            name: 'Радиально-базисная функция',
            data: []
        },{
            name: 'Сигмоид',
            color: '#333399',
            data: []
        }*/]
    });
});