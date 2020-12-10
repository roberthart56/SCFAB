Readme file for saddle project.

Prior work is documented [here](https://roberthart56.github.io/SCFAB/SC_lab/Projects/rotating_saddle/index.html)

**Dec 7-9.** 

Data below uses:
 - Five readings per data point.  Error bars give SD on the mean = SD/sqrt(5).
 - Bare sanded wood saddles.  One is slightly positive (red) and one slightly negative (blue).
 - Levelled saddles, on three bearings.
 - 19mm Polyethylene ball, released at center.
 
![figure](./Measurements/Dec7_fig.png)

[Jupyter Notebook for Dec. 7, with data for the two cases.](./Measurements/Dec7_data_nb.ipynb)

The difference at 2.5 RPS is probably significant.  Also consistent with earlier (10/30/20) results with a larger ball.  Any theoretical reason for this?

Next steps:
 - Explore role of friction.  Teflon coating, teflon ball, coated wood, steel ball.  Compare lifetimes at ~1.5 RPS
 - Go back and check 3D printed surfaces.  They may be adequate.  It would be nice to report in the paper that this method works.
 - Explore other low friction non-rolling alternatives.
 - Do a careful measurement of z(x,y) for all surfaces.
 - Design a launcher, to minimize and/or characterize dependence on initial conditions.
 
To answer questions about friction and rolling, how about studying flat plates (acrylic, epoxy, 3D PLA, etc) rotating, with sliding and rolling particles?  Should be able to solve for this motion analytically.  Will that tell us anything about the connection between rolling data and unobtainable sliding data on curved surfaces?
