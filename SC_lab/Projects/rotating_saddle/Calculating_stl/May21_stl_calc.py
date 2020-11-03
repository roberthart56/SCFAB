'''
Top layer of points in a grid, (x,y, f(x,y)).
Add a bottom layer with same grid structure.  
Make side faces.
Make bottom faces. (just two triangles)

This file used to generate saddle_21_05_20.stl with a=0.005, zbott=-15, N=101.
'''

import numpy as np
from stl import mesh

N=101
zbott = -15
a=0.005
vertices = []  

#create a list of vertices in a square pattern with zero at center.
#creates N**2 vertices from 0 to N**2-1
for i in range(N):         
    for j in range(N):     
        x=i-(N-1)/2
        y=j-(N-1)/2
        z=a*(x**2-y**2)                      #function of x and y.
        vertices.append([x, y, z])

#add to the list of vertices to make the bottom at z=-1.
#list should have 2N**2 vertices after this.
for i in range(N):         
    for j in range(N):     
        x=i-(N-1)/2
        y=j-(N-1)/2
        z=zbott                      #bottom z
        vertices.append([x, y, z])

vertices = np.array(vertices)     #turn the list into an array

faces = []

#make faces for top surface.  Use grid pattern and cover the area using all vertices.
#
for i in range(N-1):
    for j in range(N-1):
        faces.append([i*N+j, (i+1)*N+j, i*N+j+1])
        faces.append([i*N+j+1,(i+1)*N+j,(i+1)*N+j+1])

#make faces for sides.  
#
for i in range(N-1):
    faces.append([i*N, N**2+(i*N), N**2+(i+1)*N])    #front - neg y faces
    faces.append([i*N, N**2+(i+1)*N,(i+1)*N])
    
for j in range(N-1):
    faces.append([(N-1)*N+j, N**2+(N-1)*N+j, N**2+(N-1)*N+j+1])      #pos x side.
    faces.append([(N-1)*N+j, N**2+(N-1)*N+j+1,(N-1)*N+j+1])
    
for j in range(N-1):
    faces.append([j, N**2+j+1, N**2+j])      #neg x side.
    faces.append([j, j+1, N**2+j+1])

for i in range(N-1):
    faces.append([(i+1)*N -1, N**2+(i+2)*N-1,N**2+(i+1)*N -1  ])    #front - neg y faces
    faces.append([(i+1)*N -1, (i+2)*N-1, N**2+(i+2)*N-1])
    
faces.append([25, 29, 45])     #two faces for the bottom
faces.append([45, 29, 49])


faces = np.array(faces)           #turn the list into an array


# Create the mesh
surf = mesh.Mesh(np.zeros(faces.shape[0], dtype=mesh.Mesh.dtype))
for i, f in enumerate(faces):
    for j in range(3):
        surf.vectors[i][j] = vertices[f[j],:]

# Write the mesh to file "plane.stl"
surf.save('surf.stl')

#faces