        $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/2195036/fields/6,7.json?api_key=DG5Q1OBE0MW2GDTF&results=5";

                $.getJSON(url, function(data) {
                    var field1Values = [];
                    var field2Values = [];
                    var timestamps = [];

                    $.each(data.feeds, function(index, feed) {
						field1Values.push(feed.field6);
						field2Values.push(feed.field7);
						timestamps.push(feed.created_at);
					});
                    //dealing the the graph
                    var ctx = document.getElementById('myChart2').getContext('2d');

                    var chart = new Chart(ctx, {
                        type:'bar',
                        data:{
                            labels:timestamps,
                            datasets:[{
                                label: 'SpaceData1%',
                                data: field1Values,
                                backgroundColor: red(0.2),
                                borderColor:  red(1),
                                borderWidth: 1
                            },
                            {
                                label: 'SpaceData2%',
                                data: field2Values,
                                backgroundColor: blue(0.2),
                                borderColor:  blue(1),
                                borderWidth: 1                                
                                
                            }
                            
						]
                        },
                        options: {
                            scales: {
                                yAxes: [{
                                    thicks: {
                                        beginAtZero: true
                                    }
                                }]
                            }
                        }
                    });




                });

            }
            getData();

        });
