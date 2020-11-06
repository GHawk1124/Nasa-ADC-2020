import math

def generateSphere():
    vertices = []
    normals = []
    texCoords = []

    sectorCount, stackCount = 72, 36

    r = 1

    x, y, z, xy = 0, 0, 0, 0
    nx, ny, nz, lengthInv = 1/r, 1/r, 1/r, 1/r
    s, t = 0, 0

    sectorStep = 2 * math.pi / (sectorCount-1);
    stackStep = math.pi / stackCount;
    sectorAngle, stackAngle = 0, 0

    print("Generating Sphere Points...")
    
    for i in range(stackCount+1):
        stackAngle = math.pi / 2 - i * stackStep
        xy = r * math.cos(stackAngle)
        z = r * math.sin(stackAngle)

        for j in range(sectorCount+1):
            sectorAngle = j * sectorStep

            x = xy * math.cos(sectorAngle)
            y = xy * math.sin(sectorAngle)
            vertices.append(x)
            vertices.append(y)
            vertices.append(z)

            nx = x * lengthInv
            ny = y * lengthInv
            nz = z * lengthInv
            normals.append(nx)
            normals.append(ny)
            normals.append(nz)

            s = j / sectorCount
            t = i / stackCount
            texCoords.append(s)
            texCoords.append(t)

    print("Converting points to C Array...")

    cverts = []
    for idx in range(len(vertices)):
        if idx%3 == 0:
            cverts.append([])
        cverts[idx//3].append(vertices[idx])

    cnorms = []
    for idx in range(len(normals)):
        if idx%3 == 0:
            cnorms.append([])
        cnorms[idx//3].append(normals[idx])

    ctexCoords = []
    for idx in range(len(texCoords)):
        if idx%2 == 0:
            ctexCoords.append([])
        ctexCoords[idx//2].append(texCoords[idx])

    indices = []
    k1, k2 = 0, 0
    for i in range(stackCount):
        k1 = i * (sectorCount + 1)
        k2 = k1 + sectorCount + 1
        for j in range(sectorCount):
            k1 += 1
            k2 += 1
            if i != 0:
                indices.append(k1)
                indices.append(k2)
                indices.append(k1 + 1)

            if i != (stackCount-1):
                indices.append(k1 + 1)
                indices.append(k2)
                indices.append(k2 + 1)

    def generateCPPstructs(vert, norm, tex):
        print("Writing Array to File...")
        string = "#pragma once\nconst std::vector<Vertex> vertices = {\n    "
        for idx in range(len(cverts)):
            string += "{{"
            for j in range(len(cverts[idx])):
                string += str(cverts[idx][j])
                string += "f, " if j<len(cverts[idx])-1 else "f"
            string += "}, "
            string += "{0.0f, 0.0f, 0.0f}, "
            string += "{"
            for j in range(len(ctexCoords[idx])):
                string += str(ctexCoords[idx][j])
                string += "f, " if j<len(ctexCoords[idx])-1 else "f"
            string += "}}, \n     " if idx<len(cverts)-1 else "}}\n"
        string += "};\n\n"
        string += "const std::vector<uint16_t> indices = {"
        for i in range(len(indices)):
            if i%9 == 0:
                string += "\n    "
            string += str(indices[i])
            string += ", "
        string += "\n};"
        return string

    file = open("include/verts.hpp", "w")
    file.write(generateCPPstructs(cverts, cnorms, ctexCoords))
    file.close()
    print("Sphere File Generation Complete.")

if __name__ == '__main__':
    generateSphere()
